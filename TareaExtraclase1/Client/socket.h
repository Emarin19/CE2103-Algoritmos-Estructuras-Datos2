#ifndef SOCKET_H
#define SOCKET_H
#include <iostream>

class Socket
{
public:
    Socket();
    void sendMsg(std::string m);
    std::string readMsg();
private:
    int clientSocket{0};
};

#endif // SOCKET_H
