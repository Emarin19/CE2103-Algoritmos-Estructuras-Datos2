#include <iostream>
using namespace std;

/*############## TECList class definition ################*/
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

/*############## TECList class implementation ################*/
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


/*############## Node class definition ################*/
template <class T>
class Node{
public:
    static int ramdomID;
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

/*############## Node class implementation ################*/
template <class T>
int Node<T>::ramdomID = 0;

template <class T>
Node<T>::Node() {
    srand(time(0));
    ID = ramdomID++;
}

template <class T>
Node<T>::Node(T entity) {
    srand(time(0));
    ID = ramdomID++;
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
    return ramdomID++;
}

template <class T>
void Node<T>::setEntity(T entity) {
    this->entity = entity;
}

template <class T>
T Node<T>::getEntity() {
    return entity;
}

/*############## Edge class definition ################*/
class Edge{
public:
    static int randomID;
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

/*############## Edge class implementation ################*/
int Edge::randomID = 2000;

Edge::Edge() {
    srand(time(0));
    this->id = randomID++;
}

Edge::Edge(int id) {
    srand(time(0));
    this->id = id;
}

Edge::Edge(int startNode, int endNode, int weight) {
    srand(time(0));
    this->id = generateID();
    this->startNode = startNode;
    this->endNode = endNode;
    this->weight = weight;
}

Edge::~Edge() {}

void Edge::setID(int id) {
    this->id = id;
}

int Edge::getID() {
    return id;
}

int Edge::generateID() {
    return randomID++;
}

void Edge::setStartNode(int startNode) {
    this->startNode = startNode;
}

int Edge::getStartNode() {
    return startNode;
}

void Edge::setEndNode(int endNode) {
    this->endNode = endNode;
}

int Edge::getEndNode() {
    return endNode;
}

void Edge::setWeight(int weight) {
    this->weight = weight;
}

int Edge::getWeight() {
    return weight;
}

/*############## Graph class definition ################*/
class Graph{
public:
    int static randomID;
    Graph();
    ~Graph();
    void setID(int id);
    int getID();
    int generateID();
    void addNode(Node<string> node);
    void addNodes(TECList<Node<std::string>> *nodes);
    TECList<Node<std::string>> *getNodes();
    void addEdge(Edge edge);
    void addEdges(TECList<Edge> *edges);
    TECList<Edge> *getEdges();

private:
    int id;
    TECList<Node<std::string>> *nodes;
    TECList<Edge> *edges;
};

/*############## Graph class implementation ################*/
int Graph::randomID = 5000;

Graph::Graph() {
    id = randomID++;
    nodes = new TECList<Node<string>>;
    edges = new TECList<Edge>;

}

Graph::~Graph() {}

void Graph::setID(int id) {
    this->id = id;
}

int Graph::getID() {
    return id;
}

int Graph::generateID() {
    return randomID++;
}

void Graph::addNode(Node<string> node) {
    nodes->add(node);
}

void Graph::addNodes(TECList<Node<string> > *nodes) {
    for(int i=0; i<nodes->size(); i++){
        this->nodes->add(nodes->get(i));
    }
}

TECList<Node<std::string> > * Graph::getNodes() {
    return nodes;
}

void Graph::addEdge(Edge edge) {
    edges->add(edge);
}

void Graph::addEdges(TECList<Edge> *edges) {
    for(int i=0; i<edges->size(); i++){
        this->edges->add(edges->get(i));
    }
}

TECList<Edge> * Graph::getEdges() {
    return edges;
}


int main() {
    TECList<int> list;
    for(int i=1; i<=10; i++){
        list.add(i*5);
    }

    for(int i=0; i<list.size(); i++){
        cout<<list.get(i)<<" ";
    }
    cout<<"\n\n";

    Node<string> node1("Cel1");
    Node<string> node2("Cel2");
    cout<<"Node1 ID: "<<node1.getID()<<endl;
    cout<<"Node1 entity: "<<node1.getEntity()<<endl;
    cout<<"Node2 ID: "<<node2.getID()<<endl;
    cout<<"Node2 entity: "<<node2.getEntity()<<endl;
    cout<<"\n\n";

    Edge edge1(node1.getID(), node2.getID(), 12);
    cout<<"AristaID: "<<edge1.getID()<<" "<<"startNodeID: "<<edge1.getStartNode()<<" -> endNodeID: "<<edge1.getEndNode()<<endl;
    cout<<"\n\n";

    Graph graph;
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addEdge(edge1);
    cout<<"Node list size: "<<graph.getNodes()->size()<<endl;
    cout<<"Edge list size: "<<graph.getEdges()->size()<<endl;
    Node<string> nodegraph1 = graph.getNodes()->get(0);
    Node<string> nodegraph2 = graph.getNodes()->get(1);
    Edge edgegraph = graph.getEdges()->get(0);
    cout<<"Node graph1: "<<nodegraph1.getEntity()<<" ID: "<<nodegraph1.getID()<<endl;
    cout<<"Node graph2: "<<nodegraph1.getEntity()<<" ID: "<<nodegraph2.getID()<<endl;
    cout<<"Arista weight: "<<edgegraph.getWeight()<<endl;


    return 0;
}




