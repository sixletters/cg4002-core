#include <stdio.h>
#include "sensor.pb.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h> // inet_addr()
#include <sys/types.h>
#include <memory>
#include "game.hpp"
#include <vector>
#include <queue>
#include <google/protobuf/util/json_util.h>
#include "pyutil.cpp"
#include <chrono>
#include <thread>
#include <semaphore.h>
#define SA struct sockaddr
#define MAX 80
#define PORT 8080
#define SA struct sockaddr
#define BACKLOG 10
#define size_t socklen_t
#define MAXBUFFERSIZE 30

void *receiverThread(void * arg);
void *senderThread(void * arg);
void payloadParser(std::unique_ptr<Sensor> &dataPtr, Action (&playActionBuffer)[2]);
std::string sendToEvalServer(Game &currGame,int &sockfd,Pyutil &api);

// Params to be shared by thread
struct threadParams{
    pthread_mutex_t *lock;
    sem_t *empty_space;
    sem_t *fill_space;
    std::queue<std::unique_ptr<Sensor>> * DATA_BUFFER;
    int numberOfplayers;
    int port;
    char* address;
};

// Main loop
int main(int argc, char** argv){
    std::queue<std::unique_ptr<Sensor>> DATA_BUFFER;
    pthread_mutex_t lock;
    sem_t empty_space;
    sem_t fill_space;
    sem_init(&empty_space, 0, MAXBUFFERSIZE);
    sem_init(&fill_space, 0, 0);
    
    threadParams sharedParams;
       pthread_t receiver_thread, sender_thread;
    if (pthread_mutex_init(&lock, NULL) != 0) {
            std::cout<< "mutex init has failed\n";
            return 1;
    }
    sharedParams.lock = &lock;
    sharedParams.DATA_BUFFER = &DATA_BUFFER;
    sharedParams.empty_space = &empty_space;
    sharedParams.fill_space = &fill_space;
    if(argc < 2){
        std::cout<<"NOT ENOUGH ARGUMENTS";
    }
    sharedParams.address = argv[1];
    sharedParams.port = atoi(argv[2]);

    std::cout<<"Please indicate the number of players: ";
    std::cin>>sharedParams.numberOfplayers;
    if(sharedParams.numberOfplayers < 1 || sharedParams.numberOfplayers > 2){
        std::cout<<"Illegal number of players\n";
        exit(EXIT_FAILURE);
    }

    if(pthread_create(&receiver_thread, NULL, receiverThread, (void*) &sharedParams) || pthread_create(&sender_thread, NULL, senderThread, (void*) &sharedParams) ){
        std::cout<<"thread creation has failed\n";
        exit(EXIT_FAILURE);
    }
    std::cout<<"Waiting for thread to finish...\n";
    if(pthread_join(receiver_thread, NULL) || pthread_join(sender_thread, NULL)){
         std::cout<<"thread failed to join";
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
    pthread_mutex_destroy(&lock);
    sem_destroy(&fill_space);
    sem_destroy(&empty_space);
}


void * receiverThread(void *arg){
    size_t sockfd, connfd, len;
    struct sockaddr_in serv, cli;

    //params
    struct threadParams * param = (struct threadParams *) arg;

    //socket creation
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd == -1){
        std::cout<< "Socket creation failed.....\n";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<< "sucessfully created";
    };

    // intialize to zero
    bzero(&serv, sizeof(serv));

    // declare server meta data
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT);

    // bind socket
    if(bind(sockfd, (struct sockaddr *) &serv, sizeof(struct sockaddr)) != 0){
        std::cout<< "socket bind failed";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<< "socket bind suceeded";
    };


    //listen
    if((listen(sockfd,5)) != 0){
        std::cout<<"Listen Failed";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<<"Listening.....";
    }

    len = sizeof(cli);
    while(true){

        //accept connection
        connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
        if(connfd < 0){
            std::cout<<"Server acceptance Failed";
            pthread_exit((void*) "Exit");
        }else{
            std::cout<<"Server has accepted the client...\n";
        };

        /// get size of data in bytes
        int sizeOfData;
        recv(connfd, &sizeOfData, 4, 0);

        // get data and store in buffer
        std::vector<char> buf(sizeOfData+1);
        recv(connfd, buf.data(), buf.size(), 0);

        // intialize sensor from buffer data
        std::unique_ptr<Sensor> sensorPtr (new Sensor());
        sensorPtr->ParseFromArray((void*)buf.data(), buf.size()-1);

        //testing
        // std::cout<<sensorPtr->beetleid()<<"\n";
        // std::cout<<sensorPtr->playerid()<<"\n";
        // std::cout<<sensorPtr->payload().size()<<"\n";

        // acquire lock and push into databuffer
        // sem_wait(param->empty_space);
        pthread_mutex_lock(param->lock);
        param->DATA_BUFFER->push(std::move(sensorPtr));
        pthread_mutex_unlock(param->lock);
        // sem_post(param->fill_space);

        //close connection
        close(connfd);
    }
    close(sockfd);
}

void * senderThread(void * arg){
    struct threadParams * param = (struct threadParams *) arg;
    bool playerFlags[2] = {false, false};
    Action playerActionBuffer[2] = {(Action) NONE, (Action) NONE};
    std::vector<int> threadPool;
    bool playerShotMap[2] = {false,false};
    Game currGame(param->numberOfplayers);
    Pyutil api(1234);
    int sockfd;
    struct sockaddr_in servaddr;
    bool waitFlag = true;
 
    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("socket creation failed...\n");
        exit(0);
    }
    else
        printf("Socket successfully created..\n");
    bzero(&servaddr, sizeof(servaddr));
 
    // assign IP, PORT
    servaddr.sin_family = AF_INET;
    inet_pton(AF_INET, param->address, &servaddr.sin_addr.s_addr);
    servaddr.sin_port = htons(param->port);
    std::cout<<param->port<<"\n";
    std::cout<<param->address<<"\n";


    if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0){
        std::cout<<"connection failed\n";
        return 0;
    }else{
        std::cout<<"Connected to the server..\n";
    }

    while(true){

        if(param->DATA_BUFFER->size() > 0){
            // sem_wait(param->fill_space);
            pthread_mutex_lock(param->lock);
            std::unique_ptr<Sensor> dataPtr = std::move(param->DATA_BUFFER->front());
            param->DATA_BUFFER->pop();
            pthread_mutex_unlock(param->lock);
            // sem_post(param->empty_space);
            if(currGame.isSinglePlayer()){
                // Get currentPlayer
                int currPlayer = dataPtr->playerid() ;
                std::cout<<currPlayer<<"\n";
                
                if(dataPtr->beetleid() == 2 && !playerShotMap[currPlayer-1]){
                    playerShotMap[currPlayer-1] = true;
                    continue;
                }
                // PARSE AND FIND ACTION AND PUT IT IN PLAYERACTION BUFFER
                payloadParser(dataPtr, playerActionBuffer);

                //Adjust game state with player Action Buffer
                currGame.takeAction(playerShotMap, playerActionBuffer);

                // Send to evalserver and get expected game state
                std::string serializedExpectedGameState = sendToEvalServer(currGame, sockfd,api);
                currGame.synchronise(serializedExpectedGameState);
                if(playerActionBuffer[0] == EXIT){
                    close(sockfd);
                }
                for(int i=0;i<2;i++){
                    playerShotMap[i] =false;
                }
            }else{
                int currPlayer = dataPtr->playerid();

                if(playerFlags[currPlayer-1] && ((dataPtr->beetleid()%3) != 2))continue;

                if((dataPtr->beetleid()%3) == 2){
                    playerShotMap[currPlayer-1] = true;
                    continue;
                }

                playerFlags[currPlayer-1] = true;
                payloadParser(dataPtr, playerActionBuffer);
            }
        }

        if(!currGame.isSinglePlayer() && playerFlags[0] && playerFlags[1]){
            if(waitFlag){
                waitFlag = false;
                std::this_thread::sleep_for(std::chrono::milliseconds(250));
                continue;
            }
            currGame.takeAction(playerShotMap, playerActionBuffer);
            std::string serializedExpectedGameState = sendToEvalServer(currGame, sockfd,api);
            currGame.synchronise(serializedExpectedGameState);
            if(playerActionBuffer[0] == EXIT){
                close(sockfd);
            }
            for(int i=0;i<2;i++){
                playerShotMap[i] =false;
                playerFlags[i] = false;
            }
            waitFlag = true;
        }
    }
    close(sockfd);
} 

void payloadParser(std::unique_ptr<Sensor> &dataPtr, Action (&playActionBuffer)[2]){
    Pyutil api(1234);
    if(dataPtr->beetleid() == 0){
        std::cout<<"AI PREDICTION IS HERE ------------------:   ";
        playActionBuffer[dataPtr->playerid() - 1] = api.predict(dataPtr);
        std::cout<<playActionBuffer[dataPtr->playerid() - 1];
    }
    else{
        std::unordered_map<std::string, int> actionStringMap = {
        {"shield", 0},
        {"grenade", 1},
        {"reload", 2},
        {"exit", 3},
        {"shoot", 4},
        {"none", 5}
        };
        playActionBuffer[dataPtr->playerid() - 1] =(Action) actionStringMap["shoot"];
    }
}

std::string sendToEvalServer(Game &currGame,int &sockfd,Pyutil &api){

            // Serialize to Json
            std::string JsonString;
            currGame.serializeToJson(JsonString);

            std::cout<<JsonString;

            //FORMAT USING PYTHON UTILITY SERVER
            std::string encodedData = api.formatData(JsonString);
            std::cout<<encodedData;

            // Write to Buffer and send the encdoded data
            write(sockfd, encodedData.data(), encodedData.size());
            char buff[4];
            char curr;
            int i = 0;

            // Read the expected Game State;
            read(sockfd,&curr, 1);
            std::string size = "";
            while(curr != '_'){
                buff[i] = curr;
                read(sockfd, &curr, 1);
                i++;
            }
            int sizeOfData = atoi(buff);
            std::vector<char> expectedGameState(sizeOfData);
            read(sockfd,expectedGameState.data(),sizeOfData);
            std::string expectedInString(expectedGameState.begin(),expectedGameState.end());
            return expectedInString;
}
