//
// Created by emanuel on 28/2/20.
//

#include <iostream>
#include "TECList.h"

template <class T>
TECList<T>::TECList() {
    first = NULL;
    last = NULL;
}

template <class T>
TECList<T>::~TECList() {
    TECNode<T> *temp = first;
    while (temp != NULL){
        temp = temp->next;
        delete(first);
        first = temp;
    }
}

template <class T>
void TECList<T>::add(T value) {
    TECNode<T> *newNode = new TECNode<T>();
    newNode->value = value;
    newNode->next = NULL;

    TECNode<T> *temp = first;
    if(temp != NULL){
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else{
        first = newNode;
    }
}

template <class T>
void TECList<T>::add(int index, T value) {
    if(index == 0){
        TECNode<T> *new_first = new TECNode<T>();
        new_first->next = first;
        new_first->value = value;
        first = new_first;
    }
    else{
        TECNode<T> *prev = find(index-1);
        TECNode<T> *newNode = new TECNode<T>();
        newNode->value = value;
        newNode->next = prev->next;
        prev->next = newNode;
    }
}

template <class T>
TECNode<T> * TECList<T>::find(int index) {
    TECNode<T> *current = first;
    for(int i=0; i<index; i++){
        current = current->next;
    }
    return current;
}

template <class T>
T TECList<T>::get(int index) {
    if(index == 0){
        return first->value;
    }
    if(index<=size()){
        TECNode<T> *temp = first;
        for(int i=0; i<index; i++){
            temp = temp->next;
        }
        return temp->value;
    }
}

template <class T>
void TECList<T>::remove() {
    if(first == NULL && last == NULL){}
    if(first == last){
        delete(first);
        first = last = NULL;
    }
    else{
        TECNode<T> *temp = first->next;
        int counter = 0;
        while(temp != NULL){
            temp = temp->next;
            counter++;
        }

        TECNode<T> *temp2 = first;
        for(int i=0; i<(counter-1); i++){
            temp2 = temp2->next;
        }

        delete (temp2->next);
        last = temp2;
        last->next = NULL;
    }
}

template <class T>
void TECList<T>::remove(int index) {
    if(size() == 0){
        std::cout << "No item to remove in list" << std::endl;
        return;
    }
    else if (index > size() || index < 0){
        std::cout << "No item with given index" << std::endl;
        return;
    }

    TECNode<T> *current;
    if(index == 0){
        current = first;
        first = first->next;
    }
    else{
        TECNode<T> *prev = find(index-1);
        current = prev->next;
        prev->next = current->next;
    }
    current->next = NULL;
    delete(current);
    current = NULL;
}

template <class T>
int TECList<T>::size() {
    if(first == NULL && last == NULL){
        return 0;
    }

    TECNode<T> *temp = first;
    int counter = 0;
    while(temp != NULL){
        temp = temp->next;
        counter++;
    }
    return counter;
}

template <class T>
bool TECList<T>::isEmpty() {
    return first == NULL && last == NULL;
}
