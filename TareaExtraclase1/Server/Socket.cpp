//
// Created by emanuel on 4/3/20.
//

#include "Socket.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <sstream>

#define PORT 8080

/**
 * @brief create a new socket
 */
Socket::Socket() {
    readGraph();
    int server_fd;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {

        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {

        perror("listen");
        exit(EXIT_FAILURE);
    }
    //wait for connection to arrive
    serverSocket = accept(server_fd, (struct sockaddr *)&address,  (socklen_t*)&addrlen);
    if (serverSocket<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}

/**
 * @brief read a graph file
 */
void Socket::readGraph() {
    socketGraph = new Graph();
    std::fstream myFile;
    myFile.open("GraphFile", std::ios::in);

    if(myFile.fail()){
        std::cout << "File not found" << std::endl;
        return;
    }

    std::string line, word;
    std::vector<std::string> words;
    while(getline(myFile, line)){
        words.clear();
        std::stringstream s(line);

        while(getline(s, word, ',')){
            words.push_back(word);
        }

        NodeG *startNode = socketGraph->addNode(words[0]);
        NodeG *endNode = socketGraph->addNode(words[1]);
        startNode->addEdge(endNode, stoi(words[2]));
    }
    myFile.close();
}

/**
 * @brief manages external communication with clients
 * provides an interface to make communication easier between server and client
 *
 */
void Socket::controlMsg() {
    std::cout<<readMsg()<<std::endl;
    sendMsg(socketGraph->toString());
    bool active = true;
    while(active){
        std::string message(readMsg());
        if(message == "stop"){
            std::cout<<"\n program closed \n";
            active = false;
        }
        if(message == "calc"){
            std::cout << "calc" << std::endl;
            std::string x = readMsg();
            std::string y = readMsg();
            std::cout << x + y << std::endl;
            dijkstraResult src = socketGraph->shortestPath(x,y);
            if(src.dist > (std::numeric_limits<int>::max()-10000)){
                sendMsg("[no hay distancia]");
            }else{
                sendMsg(std::to_string(src.dist));
            }

            sendMsg(src.route);
            active=true;
        }
        if(message == "addNode"){
            socketGraph->addNode(readMsg());
            sendMsg(socketGraph->toString());
        }
        if(message == "addEdge"){
            std::string x = readMsg();
            std::string y = readMsg();
            int w = std::stoi(readMsg());
            socketGraph->addEdge(x,y,w);
            sendMsg(socketGraph->toString());
        }
    }
    return;
}

/**
 * @brief send the request to the client
 * @param msg
 */
void Socket::sendMsg(std::string msg) {
    const char* msgs = msg.c_str();
    send(serverSocket , msgs , strlen(msgs) , 0 );
}

/**
 * @brief read the message that user sent
 * @return
 */
std::string Socket::readMsg() {
    char buffer[1024] = {0};
    read(serverSocket, buffer, 1024);
    std::string msg(buffer);
    return msg;
}

