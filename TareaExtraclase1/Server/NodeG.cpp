//
// Created by emanuel on 4/3/20.
//

#include "NodeG.h"
#include "Vertex.h"
#include <iostream>
#include <string>
#include "TecList.h"


NodeG::NodeG(std::string x){
    value = x;
}
NodeG::NodeG(const NodeG& x){
    value = x.value;
    vertexList = x.vertexList;
}
NodeG::~NodeG(){
    DDList::Node<Vertex*>* x = vertexList.first;
    while(x!=0){
        delete x->data;
        x=x->next;
    }
    vertexList.clear();
}
void NodeG::addEdge(NodeG* x, int weight){
    Vertex *n = new Vertex(x, weight);
    vertexList.add(n);
}
DDList::LinkedList<Vertex *>* NodeG::getEdges(){
    return &vertexList;
}
void NodeG::removeEdge(std::string x){
    vertexList.customRemove(x);
}
std::string NodeG::getValue(){
    return this->value;
}
void NodeG::lookUpEdges(){
    std::cout<<vertexList.toString();
}
template<>
std::string DDList::LinkedList<NodeG* >::toString(){
    std::string res{};
    Node<NodeG* > *x = first;
    while(x!=0){
        res+=x->data->getValue()+": ";
        res+=x->data->getEdges()->toString();
        x = x->next;
    }
    res+="\n";
    return res;
}