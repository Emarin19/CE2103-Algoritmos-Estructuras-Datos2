//
// Created by emanuel on 4/3/20.
//

#ifndef SERVER_GRAPH_H
#define SERVER_GRAPH_H
#include <string>
#include "TecList.h"
#include "NodeG.h"
#include "Vertex.h"

struct dijkstraResult{
    std::string route;
    int dist;
};
class NodeG;
class Vertex;
struct dijkstraInfo;
class Graph
{
private:
    DDList::LinkedList<NodeG*> nodes;
    dijkstraInfo* getNearestUnvisited(DDList::LinkedList<dijkstraInfo*>& dijkstraMatrix, DDList::LinkedList<NodeG*>& toVisit);
public:
    NodeG* addNode(std::string x);
    void addEdge(std::string x, std::string y, int w);
    std::string toString();
    dijkstraResult shortestPath(std::string from, std::string to);
};

#endif //SERVER_GRAPH_H
