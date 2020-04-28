//
// Created by emanuel on 4/3/20.
//

#ifndef SERVER_TECLIST_H
#define SERVER_TECLIST_H
#include <iostream>

namespace DDList{
//definition of a node class
    template<class T>
    class Node
    {
    public:
        T data{};
        Node* next;
        Node* prev;
        Node(T data){
            next = {0};
            prev = {0};
            this->data = data;
        }
    };

//definition of class to iterate trough nodes
    template<class T>
    struct INode
    {
        Node<T> *n;
        INode<T>(Node<T> *node) : n(node) {} //constructor
        bool operator!=(INode<T> rhs) {return n != rhs.n;}
        Node<T>& operator*() {return *n;}
        void operator++() {n=n->next;}
    };

    template<class T>
/**
 * @brief Template Linked List data structure with various methods that faiclitate usage
 *
 */
    class LinkedList{
    private:
        int size{0};

        void addFirst(T data);
        Node<T>* getNode(int index);
    public:
        Node<T>* first;
        Node<T>* last;
        template <typename E>
        friend bool operator==(LinkedList<E> &a, LinkedList<E> &b);
        LinkedList(){first = last = 0;}
        LinkedList(const DDList::LinkedList<T>& x){
            first = last = 0;
            Node<T> * c = x.first;
            while(c!=0){
                add(c->data);
                c=c->next;
            }
        }
        ~LinkedList(){
            beforeClear();
            clear();
        }
        INode<T> begin();
        INode<T> end();
        T& operator[] (int index){return get(index);}
        void add(T data);
        void add(T data, int index);
        void set(int index, T data);
        T& get(int index);
        template<class E>
        T search(E data); //external overload
        T pop();
        void remove(int index);
        void removeVal(T data);
        template <class E>
        void customRemove(E x);
        void beforeClear();
        void clear();
        int getSize(){return size;}
        bool contains(T data);
        bool isEmpty();
        std::string toString();
    };
    template<typename T>
/**
 * @brief provides begin() for for range loops
 *
 * @return INode<T>
 */
    INode<T> LinkedList<T>::begin(){
        return first;
    }
    template<typename T>
/**
 * @brief provides end() for for range loops
 *
 * @return INode<T>
 */
    INode<T> LinkedList<T>::end(){
        return last->next;
    }

    template<typename T>
/**
 * @brief adds a new node to the list at the end
 *
 * @param data
 */
    void LinkedList<T>::add(T data){
        Node<T> *x  = new Node<T>(data);
        if (isEmpty()){
            first = last= x;
            first->next = last->prev = {0}; //cagada
        }else{
            last->next = x;
            x->prev = last;
            last = x;
        }
        ++size;
    }
    template<typename T>
/**
 * @brief adds element at the beggining
 *
 * @param data
 */
    void LinkedList<T>::addFirst(T data){
        Node<T> *x = new Node<T>{data};
        if (isEmpty()){
            first = last= x;
            first->next = last->prev = x;
        }else{
            first->prev = x;
            x->next = first;
            first = x;
        }
        ++size;
    }
    template<typename T>
/**
 * @brief adds a node at the position specified
 *
 * @param data
 * @param index
 */
    void LinkedList<T>::add(T data, int index){
        if(index == 0){
            addFirst(data);
        }else if(index>=size){
            add(data);
        }else{
            Node<T> *c = this->first;
            for(int i = 0; i<index;i++){
                c = c->next;
            }
            Node<T> *x = new Node<T>(data);
            x->prev = (c->prev);
            x->next = c;
            (c->prev)->next = x;
            (c->prev) = x;
            ++size;
        }
    }
    template<typename T>
/**
 * @brief changes the value in one position
 *
 * @param index
 * @param data
 */
    void LinkedList<T>::set(int index, T data){
        if (index>size){
            return;
        }
        Node<T> *c= first;
        int cnt{0};
        while (c!=0 && cnt<index){
            ++cnt;
            c = c->next;
        }
        c->data = data;
    }
    template<typename T>
/**
 * @brief returns the value stores in the position specified
 *
 * @param index
 * @return T&
 */
    T& LinkedList<T>::get(int index){
        //returns last value if the index is
        //higher than the size
        if (index>size-1){
            return (last->data);
        }
        Node<T> *c= first;
        int cnt{0};
        while (c!=0 && cnt<index)
        {
            ++cnt;
            c = c->next;
        }
        return (c->data);
    }
    template<typename T>
/**
 * @brief returns the NodeG object in the position specified
 *
 * @param index
 * @return NodeG<T>*
 */
    Node<T>* LinkedList<T>::getNode(int index){
        if (index>size-1){
            return 0;
        }
        Node<T> *c= first;
        int cnt{0};
        while (c!=0 && cnt<index)
        {
            ++cnt;
            c = c->next;
        }
        return c;
    }
    template<typename T>
/**
 * @brief detatches last value from the list, and returns what it contained
 *
 * @return T
 */
    T LinkedList<T>::pop(){
        T data{};
        if(!isEmpty()){
            data = last->data;
            Node<T>* d =  last;
            last = d->prev;
            last->next = 0;
            delete d;
            --size;
        }
        return data;
    }
    template<typename T>
/**
 * @brief removes element based on the position given
 *
 * @param index
 */
    void LinkedList<T>::remove(int index){
        if(isEmpty()){return;}
        Node<T>* dn = getNode(index);
        if(index == 0){
            first = first->next;
            T d = dn->data;
            delete dn;
            if(!isEmpty()){
                first->prev = 0;
            }else{
                last = 0;
            }
            size--;
            return;
        }else if(index == (size-1)){
            pop();
        }else{
            dn->prev->next = dn->next;
            dn->next->prev = dn->prev;
            delete dn;
            --size;
        }
        return;
    }
    template<typename T>
/**
 * @brief searches for a NodeG with the same value that was specified and removes it from the list
 *
 * @param data
 */
    void LinkedList<T>::removeVal(T data){
        Node<T>* c = first;
        while (c!=0){
            if(c->data == data){
                if(c==first){
                    remove(0);
                }else if(c==last){
                    pop();
                }else{
                    c->prev->next = c->next;
                    c->next->prev = c->prev;
                    delete c;
                    --size;
                }
                return;
            }
            c = c->next;
        }
        return;
    }
    template<typename T>
/**
 * @brief deletes all the nodes from the list
 *
 */
    void LinkedList<T>::clear(){
        while (!isEmpty())
        {
            remove(0);
        }
    }
    template<typename T>
/**
 * @brief checks if the list contains the data specified
 *
 * @param data
 * @return true
 * @return false
 */
    bool LinkedList<T>::contains(T data){
        Node<T> *c= first;
        bool result{false};
        while (c!=0)
        {
            if(c->data == data){
                result = true;
                c=0;
            }else{
                c = c->next;
            }
        }
        return result;
    }
    template<typename T>
    bool LinkedList<T>::isEmpty(){
        return (first==0);
    }
/**
 * @brief overload of == operator to facilitate comparisons with other lists of the same type
 *
 * @param a first list
 * @param b second list
 * @return true
 * @return false
 */
    template<typename E>
    bool operator==(LinkedList<E> &a, LinkedList<E> &b){
        Node<E>* x = a.first;
        Node<E>* y = b.first;
        if(a.size!=b.size) {return false;}
        while(x!=0 && y!=0){
            if (x->data != y->data){
                return false;
            }
            x = x->next;
            y = y->next;
        }
        return true;
    }
/**
 * @brief function that can be overloaded. Useful to transform the list into a string that can be communicated
 *
 * @tparam T
 * @return std::string
 */
    template<typename T>
    std::string  LinkedList<T>::toString(){
        std::string res{};
        res+="----------------- \n";
        Node<T> *x = first;
        while(x!=0){
            //res+="["+std::string(x->data)+"]\n";
            x = x->next;
        }
        res+="----------------- \n";
        return res;
    }
/**
 * @brief overload in case an operation before deletion is required
 *
 * @tparam T
 */
    template<typename T>
    void LinkedList<T>::beforeClear(){
        return;
    }
}

#endif //SERVER_TECLIST_H
