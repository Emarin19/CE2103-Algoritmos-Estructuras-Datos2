cmake_minimum_required(VERSION 3.16)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server main.cpp Socket.cpp Socket.h Graph.cpp Graph.h TecList.h Vertex.cpp Vertex.h NodeG.cpp NodeG.h)