//
// Created by emanuel on 4/3/20.
//

#ifndef SERVER_VERTEX_H
#define SERVER_VERTEX_H

class NodeG;
class Vertex{
private:
    NodeG* target;
    int weight;
public:
    Vertex(NodeG* x, int w);
    Vertex(const Vertex& x);
    ~Vertex(){
        return;
    }
    NodeG* getTarget();
    int getWeight();
};

#endif //SERVER_VERTEX_H
