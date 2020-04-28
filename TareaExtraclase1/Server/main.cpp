#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <cstring>
#include <string>
#include <iostream>

#include "Graph.h"
#include "NodeG.h"
#define PORT 8080
#include "Socket.h"

int main()
{
    Socket *server = new Socket();
    server->controlMsg();
    return 0;
}