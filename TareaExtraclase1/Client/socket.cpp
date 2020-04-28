#include "socket.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <iostream>
#define PORT 8080

Socket::Socket()
{
    sockaddr_in serv_addr;
    if((clientSocket = socket(AF_INET, SOCK_STREAM, 0 ))<0){
        printf("socket creation error");
        throw "socket failed";
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("Invalid address/ Address not supported");
        throw "socket failed";
    }

    if (connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Connection Failed");
        throw "socket failed";
    }

    char hello[] = "New client connected";
    send(clientSocket , hello , strlen(hello) , 0 );
}

void Socket::sendMsg(std::string m){
    const char* msg = m.c_str();
    send(clientSocket , msg , strlen(msg) , 0 );
}

std::string Socket::readMsg(){
    char buffer[1024] = {0};
    read(clientSocket, buffer, 1024);
    std::string msg(buffer);
    return msg;
}
