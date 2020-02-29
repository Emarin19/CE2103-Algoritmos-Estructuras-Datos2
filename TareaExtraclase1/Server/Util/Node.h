//
// Created by emanuel on 29/2/20.
//

#ifndef SERVER_NODE_H
#define SERVER_NODE_H

template <class T>
class Node{
public:
    Node();
    Node(T);
    ~Node();
    void setID(int);
    int getID();
    int generateID();
    void setEntity(T);
    T getEntity();

private:
    int ID;
    T entity;
};

#endif //SERVER_NODE_H
