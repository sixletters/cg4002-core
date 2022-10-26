#include "sensor.pb.h"
#include <vector>
#include "player.hpp"
#include <arpa/inet.h> // inet_addr()
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h> // bzero()
#include <sys/socket.h>
#include <unistd.h> // read(), write(), close()

class Pyutil{
    public:
        Pyutil (int port): port(port){};
        Action predict(std::unique_ptr<Sensor> &dataPtr){
            std::string data;
            dataPtr->SerializeToString(&data);
            // insert API code
            data.insert (0, 1, 0x00); 

            int sockfd;
            struct sockaddr_in servaddr;
        
            // socket create and verification
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                printf("socket creation to utility server failed...\n");
                exit(0);
            }
            else{
                printf("Socket successfully created to utility server..\n");
            }
            bzero(&servaddr, sizeof(servaddr));
        
            // assign IP, PORT
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            servaddr.sin_port = htons(this->port);
            if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0){
                std::cout<<"connection failed\n";
            }else{
                std::cout<<"Connected to the server..\n";
            }
            write(sockfd,data.data(),data.size());
            char buffer[1];
            read(sockfd,&buffer,1);
            close(sockfd);
            std::cout<<buffer;
            int predicted= atoi(buffer);
            std::cout<<"ACTION HERE\n";
            std::cout<<predicted<<"\n";
            return (Action) predicted;
        };
        std::string formatData(std::string jsonString){
            int sockfd;
            struct sockaddr_in servaddr;
            sockfd = socket(AF_INET, SOCK_STREAM,0);
            if (sockfd == -1) {
                printf("socket creation to utility server failed...\n");
                exit(0);
            }
            else{
                printf("Socket successfully created to utility server..\n");
            }
            bzero(&servaddr, sizeof(servaddr));
            servaddr.sin_family = AF_INET;
            servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
            servaddr.sin_port = htons(this->port);

            if(connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0){
                std::cout<<"connection failed\n";
                return 0;
            }else{
                std::cout<<"Connected to the server..\n";
            }

            jsonString.insert (0, 1, 0x01); 
            write(sockfd,jsonString.data(),jsonString.size());
            int i = 0;
            char buff[4];
            char curr;
            read(sockfd,&curr, 1);
            while(curr != '_'){
                buff[i] = curr;
                read(sockfd, &curr, 1);
                i++;
            }
            buff[i] = '\0';
            int sizeOfData = atoi(buff);
            std::vector<char> buffer(sizeOfData);
            read(sockfd,buffer.data(),sizeOfData);
            close(sockfd);
            std::string formattedData(buffer.begin(), buffer.end());
            return formattedData;
        };
    private:
    int port;


};