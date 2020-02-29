//
// Created by emanuel on 28/2/20.
//

#ifndef SERVER_TECLIST_H
#define SERVER_TECLIST_H

#include <iostream>

template <class T>
struct TECNode{
    T value;
    TECNode *next;
};

template <class T>
class TECList {
public:
    TECList();
    ~TECList();
    void add(T);
    void add(int, T);
    T get(int);
    void remove();
    void remove(int);
    bool isEmpty();
    int size();
    TECNode<T> *find(int index);


private:
    TECNode<T> *first;
    TECNode<T> *last;
};

#endif //SERVER_TECLIST_H
