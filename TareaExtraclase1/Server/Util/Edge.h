//
// Created by emanuel on 29/2/20.
//

#ifndef SERVER_EDGE_H
#define SERVER_EDGE_H

class Edge{
public:
    Edge();
    Edge(int id);
    Edge(int startNode, int endNode, int weight);
    ~Edge();
    void setID(int id);
    int getID();
    int generateID();
    void setStartNode(int startNode);
    int getStartNode();
    void setEndNode(int endNode);
    int getEndNode();
    void setWeight(int weight);
    int getWeight();

private:
    int id;
    int startNode;
    int endNode;
    int weight;
};

#endif //SERVER_EDGE_H
