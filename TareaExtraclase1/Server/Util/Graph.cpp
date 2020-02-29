//
// Created by emanuel on 29/2/20.
//

#include "Graph.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Graph::Graph() {
    srand(time(0));
    this->id = generateID();
    this->nodes = new TECList<Node<std::string>>;
    this->edges = new TECList<Edge>;
}

Graph::~Graph() {}

void Graph::setID(int id) {
    this->id = id;
}

int Graph::getID() {
    return id;
}

int Graph::generateID() {
    return rand()% 1000+1;
}

void Graph::setNodes(TECList<Node<std::string> > *nodes) {
    for(int i=0; i<nodes->size(); i++){
        this->nodes->add(nodes->get(i));
    }
}

TECList<Node<std::string> > * Graph::getNodes() {
    return nodes;
}

void Graph::setEdges(TECList<Edge> *edges) {
    for(int i=0; i<edges->size(); i++){
        this->edges->add(edges->get(i));
    }
}

TECList<Edge> * Graph::getEdges() {
    return edges;
}