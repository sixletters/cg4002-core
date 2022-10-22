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
#include <sys/types.h>
#include <memory>
#include <vector>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr
#define BACKLOG 10
#define size_t socklen_t

void *receiverThread(void * arg);
void *senderThread(void * arg);

struct threadParams{
    pthread_mutex_t *lock;
    std::vector<std::unique_ptr<Sensor>> * DATA_BUFFER;
};

int main(){
    std::vector<std::unique_ptr<Sensor>> DATA_BUFFER;
    pthread_mutex_t lock;
    threadParams sharedParams;
       pthread_t receiver_thread, sender_thread;
    if (pthread_mutex_init(&lock, NULL) != 0) {
            std::cout<< "mutex init has failed\n";
            return 1;
    }
    sharedParams.lock = &lock;
    sharedParams.DATA_BUFFER = &DATA_BUFFER;
        int ret;

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
}


void * receiverThread(void *arg){
    size_t sockfd, connfd, len;
    struct sockaddr_in serv, cli;

    struct threadParams * param = (struct threadParams *) arg;
    sockfd = socket(AF_INET, SOCK_STREAM,0);
    if(sockfd == -1){
        std::cout<< "Socket creation failed.....\n";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<< "sucessfully created";
    };
    bzero(&serv, sizeof(serv));

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    serv.sin_port = htons(PORT);
    if(bind(sockfd, (struct sockaddr *) &serv, sizeof(struct sockaddr)) != 0){
        std::cout<< "socket bind failed";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<< "socket bind suceeded";
    };

    if((listen(sockfd,5)) != 0){
        std::cout<<"Listen Failed";
        pthread_exit((void*) "Exit");
    }else{
        std::cout<<"Listening.....";
    }

    len = sizeof(cli);
    while(true){
        connfd = accept(sockfd, (struct sockaddr *) &cli, &len);
        if(connfd < 0){
            std::cout<<"Server acceptance Failed";
            pthread_exit((void*) "Exit");
        }else{
            std::cout<<"Server has accepted the client...\n";
        };
        int sizeOfData;
        recv(connfd, &sizeOfData, 4, 0);
        std::vector<char> buf(sizeOfData+1);
        recv(connfd, buf.data(), buf.size(), 0);
        std::unique_ptr<Sensor> sensorPtr (new Sensor());
        sensorPtr->ParseFromArray((void*)buf.data(), buf.size()-1);
        std::cout<<sensorPtr->beetleid()<<"\n";
        std::cout<<sensorPtr->playerid()<<"\n";
        std::cout<<sensorPtr->payload().size()<<"\n";
        pthread_mutex_lock(param->lock);
        param->DATA_BUFFER->push_back(std::move(sensorPtr));
        pthread_mutex_unlock(param->lock);
        close(connfd);
    }
    close(sockfd);
}

void * senderThread(void * arg){
    struct threadParams * param = (struct threadParams *) arg;
    pthread_mutex_lock(param->lock);
    while(true){
        sleep(1);
        std::cout<<param->DATA_BUFFER->size()<<"\n";
        pthread_mutex_unlock(param->lock);
    }

}