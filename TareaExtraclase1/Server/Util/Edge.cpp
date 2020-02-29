//
// Created by emanuel on 29/2/20.
//

#include "Edge.h"
#include <cstdlib>
#include <ctime>

Edge::Edge() {
    srand(time(0));
    this->id = generateID();
}

Edge::Edge(int id) {
    srand(time(0));
    this->id = id;
}

Edge::Edge(int startNode, int endNode, int weight) {
    srand(time(0));
    this->id = generateID();
    this->startNode = startNode;
    this->endNode = endNode;
    this->weight = weight;
}

Edge::~Edge() {}

void Edge::setID(int id) {
    this->id = id;
}

int Edge::getID() {
    return id;
}

int Edge::generateID() {
    return rand() % 1000+1;
}

void Edge::setStartNode(int startNode) {
    this->startNode = startNode;
}

int Edge::getStartNode() {
    return startNode;
}

void Edge::setEndNode(int endNode) {
    this->endNode = endNode;
}

int Edge::getEndNode() {
    return endNode;
}

void Edge::setWeight(int weight) {
    this->weight = weight;
}

int Edge::getWeight() {
    return weight;
}