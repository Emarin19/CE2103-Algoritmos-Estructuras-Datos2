//
// Created by emanuel on 4/3/20.
//

#include "Graph.h"
#include "NodeG.h"
#include "Vertex.h"
#include <iostream>
#include <limits>

/**
 * @brief struct that stores the result from the shortest path calculation
 *
 */
struct dijkstraInfo{
    NodeG* node{};
    int distance;
    NodeG* predecesor{};
};

template<>
/**
 * @brief invoques custom destructor to avoid memory leaks. be aware that this is called
 * when a vertex* list is passed by value
 *
 */
void DDList::LinkedList<Vertex *>::beforeClear(){
    Node<Vertex*>* c= first;
    while(c!= 0){
        delete c->data;
        c = c->next;
    }
    clear();
}

template<>
template<>
/**
 * @brief searches a graph node based on it's name
 *
 * @param x name of the value o be looked for
 * @return NodeG*
 */
NodeG* DDList::LinkedList<NodeG *>::search<std::string>(std::string x){
    Node<NodeG*>* c = first;
    while (c!=0)
    {
        if(c->data->getValue() == x){
            return c->data;
        }
        c = c->next;
    }
    return 0;
}


template<>
template<>
/**
 * @brief searches for a row in the table containing the information produced by dijkstra's algorithm
 *
 * @param x pointer to the value of node to be looked for
 * @return dijkstraInfo* pointer to the row in the information table
 */
dijkstraInfo* DDList::LinkedList<dijkstraInfo*>::search<NodeG*>(NodeG* x){
    Node<dijkstraInfo*>* c = first;
    while (c!=0)
    {
        if(c->data->node == x){
            return c->data;
        }
        c = c->next;
    }
    return {0}; // no connection to dereference;
}



/**
 * @brief adds a node to the graph
 *
 * @param x name of the node
 * @return NodeG* pointer to the added node in case it is required for additional operations
 */
NodeG* Graph::addNode(std::string x){
    NodeG* y = new NodeG(x);
    nodes.add(y);
    return y;
}
/**
 * @brief adds an edge to the graph based on the names of the involved nodes
 *
 * @param x origin node
 * @param y destiny node
 * @param w weight of the edge
 */
void Graph::addEdge(std::string x, std::string y, int w){
    nodes.search(x)->addEdge(nodes.search(y), w);
}
/**
 * @brief
 *
 * @return std::string
 */
std::string Graph::toString(){
    return nodes.toString();
}
/**
 * @brief
 *
 * @param dijkstraMatrix
 * @param toVisit
 * @return dijkstraInfo*
 */
dijkstraInfo* Graph::getNearestUnvisited(DDList::LinkedList<dijkstraInfo*>& dijkstraMatrix, DDList::LinkedList<NodeG*>& toVisit){
    int minDist{std::numeric_limits<int>::max()-1000};
    dijkstraInfo* result{};
    for(int i= 0; i<dijkstraMatrix.getSize();i++){
        if(dijkstraMatrix[i]->distance < minDist && toVisit.contains(dijkstraMatrix[i]->node)){
            result = dijkstraMatrix[i];
            minDist = result->distance;
        }
    }
    if(result==0){
        return dijkstraMatrix.search(toVisit.first->data);
    }
    return result;
}
/**
 * @brief
 *
 * @param from
 * @param to
 * @return dijkstraResult
 */
dijkstraResult Graph::shortestPath(std::string from, std::string to){
    DDList::LinkedList<NodeG*> toVisit = nodes;
    DDList::LinkedList<dijkstraInfo*> dijkstraMatrix;
    NodeG* src = toVisit.search(from);
    NodeG* obj = toVisit.search(to);
    //creates table that contains shortestPath route
    dijkstraInfo* i{};
    DDList::Node<NodeG* >* x = toVisit.first;
    while(x!=0)
    {
        i = (x->data == src)? new dijkstraInfo{x->data, 0, 0} : new dijkstraInfo{x->data, std::numeric_limits<int>::max()-1000, 0};
        dijkstraMatrix.add(i);
        x=x->next;
    }
    while(!toVisit.isEmpty())
    {

        dijkstraInfo* currentVertex = getNearestUnvisited(dijkstraMatrix, toVisit);
        //searches all the neighbours from the current node and updates de information table
        DDList::LinkedList<Vertex *>* neighbours;
        neighbours = currentVertex->node->getEdges();
        DDList::Node<Vertex* >* c = neighbours->first;
        while(c!=0)
        {

            dijkstraInfo* i = dijkstraMatrix.search(c->data->getTarget());
            int calcDistance = currentVertex->distance + c->data->getWeight();

            if(i!=0){
                if(i->distance > calcDistance){
                    i->distance = calcDistance;
                    i->predecesor = currentVertex->node;
                }
            }
            c= c->next;
        }
        toVisit.removeVal(currentVertex->node);
    }
    dijkstraInfo* sp = dijkstraMatrix.search(obj);
    int res = sp->distance;
    //
    std::string p=obj->getValue();
    while(sp->predecesor != 0){
        p+="<-"+sp->predecesor->getValue();
        sp = dijkstraMatrix.search(sp->predecesor);
    }
    dijkstraResult finalRes{p, res};
    return finalRes;
}
