#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

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
    Edge(Node<string> startNode, Node<string> endNode, int weight);
    ~Edge();
    void setID(int id);
    int getID();
    int generateID();
    void setStartNode(Node<string>);
    Node<string> getStartNode();
    void setEndNode(Node<string>);
    Node<string> getEndNode();
    void setWeight(int weight);
    int getWeight();

private:
    int id;
    Node<string> startNode;
    Node<string> endNode;
    int weight;
};

/*############## Edge class implementation ################*/
int Edge::randomID = 2000;

Edge::Edge() {
    this->id = randomID++;
}

Edge::Edge(int id) {
    this->id = id;
}

Edge::Edge(Node<string> startNode, Node<string> endNode, int weight) {
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

void Edge::setStartNode(Node<string> startNode) {
    this->startNode = startNode;
}

Node<string> Edge::getStartNode() {
    return startNode;
}

void Edge::setEndNode(Node<string> endNode) {
    this->endNode = endNode;
}

Node<string> Edge::getEndNode() {
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

void loadGraph(Graph &);

int main() {
    Graph graph;
    loadGraph(graph);

    cout<<"Nodes: "<<graph.getNodes()->size()<<endl;
    cout<<"Edges: "<<graph.getEdges()->size()<<endl;
    for(int i=0; i<graph.getNodes()->size(); i++){
        cout<<graph.getNodes()->get(i).getEntity()<<" ";
    }
    cout<<endl;

    for(int i=0; i<graph.getEdges()->size(); i++){
        cout<<"start: "<<graph.getEdges()->get(i).getStartNode().getEntity()
        <<", end: "<<graph.getEdges()->get(i).getEndNode().getEntity()<<", weight: "
        <<graph.getEdges()->get(i).getWeight()<<endl;
    }

    return 0;
}


void loadGraph(Graph &graph){
    fstream file;
    file.open("GraphFile",ios::in);

    if(file.fail()){
        cout<<"File not found"<<endl;
        return;
    }

    string line, word;
    vector<string> words;
    while(getline(file,line)){
        words.clear();
        stringstream s(line);

        while(getline(s,word,',')){
            words.push_back(word);
        }

        Node<string> startNode(words[0]);
        Node<string> endNode(words[1]);
        Edge edge(startNode, endNode, stoi(words[2]));

        graph.addNode(startNode);
        graph.addNode(endNode);
        graph.addEdge(edge);
    }
    file.close();
}




