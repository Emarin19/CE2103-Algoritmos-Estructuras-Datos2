//
// Created by emanuel on 4/3/20.
//

#ifndef SERVER_NODEG_H
#define SERVER_NODEG_H
#include <string>
#include "TecList.h"
class Vertex;
class NodeG{
private:
    std::string value;
    DDList::LinkedList<Vertex *> vertexList;
public:
    operator std::string() const {return value;};
    NodeG(std::string x);
    NodeG(const NodeG& x);
    ~NodeG();
    void addEdge(NodeG* x, int weight);
    DDList::LinkedList<Vertex *>* getEdges();
    void removeEdge(std::string x);
    void lookUpEdges();
    std::string getValue();
};
#endif //SERVER_NODEG_H
