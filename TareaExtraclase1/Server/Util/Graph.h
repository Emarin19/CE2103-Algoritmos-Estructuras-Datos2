//
// Created by emanuel on 29/2/20.
//

#ifndef SERVER_GRAPH_H
#define SERVER_GRAPH_H

#include <iostream>
#include <string>
#include "TECList.h"
#include "Node.h"
#include "Edge.h"

class Graph{
public:
    Graph();
    ~Graph();
    void setID(int id);
    int getID();
    int generateID();
    void setNodes(TECList<Node<std::string>> *nodes);
    TECList<Node<std::string>> *getNodes();
    void setEdges(TECList<Edge> *edges);
    TECList<Edge> *getEdges();

private:
    int id;
    TECList<Node<std::string>> *nodes;
    TECList<Edge> *edges;
};

#endif //SERVER_GRAPH_H
