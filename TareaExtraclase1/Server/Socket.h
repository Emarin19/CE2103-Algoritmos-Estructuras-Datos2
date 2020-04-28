//
// Created by emanuel on 4/3/20.
//

#ifndef SERVER_SOCKET_H
#define SERVER_SOCKET_H
#include <string>
#include "Graph.h"

class Socket
{
private:
    Graph* socketGraph;
    int serverSocket;
public:
    Socket();
    void readGraph();
    void controlMsg();
    void sendMsg(std::string msg);
    std::string readMsg();
};

#endif //SERVER_SOCKET_H
