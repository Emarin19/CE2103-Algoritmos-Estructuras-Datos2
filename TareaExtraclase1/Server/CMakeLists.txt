cmake_minimum_required(VERSION 3.15)
project(Server)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server Util/main.cpp Pruebas/Person.cpp Pruebas/Person.h Pruebas/Student.cpp Pruebas/Student.h Pruebas/Employee.cpp Pruebas/Employee.h Util/TECList.cpp Util/TECList.h Util/Node.cpp Util/Node.h Util/Edge.cpp Util/Edge.h Util/Graph.cpp Util/Graph.h)