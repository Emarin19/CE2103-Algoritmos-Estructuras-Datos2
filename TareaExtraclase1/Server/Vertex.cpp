//
// Created by emanuel on 4/3/20.
//

#include "Vertex.h"
#include "NodeG.h"
#include "TecList.h"

/**
 * @brief Construct a new Vertex:: Vertex object
 *
 * @param x
 * @param w
 */
Vertex::Vertex(NodeG* x, int w) : target{x}, weight{w} {}
/**
 * @brief Construct a new Vertex:: Vertex object
 *
 * @param x
 */
Vertex::Vertex(const Vertex& x) : target{x.target},weight{x.weight}{}
/**
 * @brief
 *
 * @return NodeG*
 */
NodeG* Vertex::getTarget(){
    return target;
}
/**
 * @brief
 *
 * @return int
 */
int Vertex::getWeight(){
    return weight;
}


template<>
/**
 * @brief
 *
 * @return std::string
 */
std::string DDList::LinkedList<Vertex* >::toString(){
    std::string res{};
    Node<Vertex *> *x = first;
    while(x!=0){
        res+="["+(x->data->getTarget()->getValue())+","+std::to_string(x->data->getWeight())+"]";
        x = x->next;
    }
    res+="\n";
    return res;
}

template<>
template<>
/**
 * @brief
 *
 * @param x
 */
void DDList::LinkedList<Vertex*>::customRemove<std::string>(std::string x){
    DDList::Node<Vertex*>* c = first;
    while(c!= 0){
        if(c->data->getTarget()->getValue() == x){
            removeVal(c->data);
            break;
        }
        else{
            c = c->next;
        }
    }

}