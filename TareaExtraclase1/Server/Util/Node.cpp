//
// Created by emanuel on 29/2/20.
//

#include <cstdlib>
#include <ctime>
#include "Node.h"

template <class T>
Node<T>::Node() {
    srand(time(0));
    ID = generateID();
}

template <class T>
Node<T>::Node(T entity) {
    srand(time(0));
    ID = generateID();
    this->entity = entity;
}

template <class T>
Node<T>::~Node() {}

template <class T>
void Node<T>::setID(int id) {
    ID = id;
}

template <class T>
int Node<T>::getID() {
    return ID;
}

template <class T>
int Node<T>::generateID() {
    return rand() % 1000+1;
}

template <class T>
void Node<T>::setEntity(T entity) {
    this->entity = entity;
}

template <class T>
T Node<T>::getEntity() {
    return entity;
}