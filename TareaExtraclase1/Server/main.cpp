#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>

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
    void setVisited(bool);
    bool isVisited();

private:
    int ID;
    T entity;
    bool visited;
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

template <class T>
void Node<T>::setVisited(bool visited) {
    this->visited = visited;
}

template <class T>
bool Node<T>::isVisited() {
    return visited;
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
    void setWeight(int _weight);
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

void Edge::setWeight(int _weight) {
    weight = _weight;
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
    bool containsNode(Node<string> &);
    bool containsEdge(Edge &);

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
    //cout<<"El resultado de contains entonces es: "<<containsNode(node)<<endl;
    if(containsNode(node) == false){
        nodes->add(node);
    }
    else{
        cout<<node.getEntity()<<" ya existe"<<endl;
    }
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
    if(containsEdge(edge) == false){
        edges->add(edge);
    }
    else{
        cout<<"Edge ya existe"<<endl;
    }

}

void Graph::addEdges(TECList<Edge> *edges) {
    for(int i=0; i<edges->size(); i++){
        this->edges->add(edges->get(i));
    }
}

TECList<Edge> * Graph::getEdges() {
    return edges;
}

bool Graph::containsNode(Node<string> &node) {
    bool result = false;
    for(int i=0; i<nodes->size(); i++){
        if((nodes->get(i).getEntity().compare(node.getEntity())) == 0){
            cout<<nodes->get(i).getEntity()<<" es igual a "<<node.getEntity()<<endl;
            result = true;
            break;
        }
    }
    return result;
}

bool Graph::containsEdge(Edge &edge) {
    bool result = false;
    for(int i=0; i<edges->size(); i++){
        if((edges->get(i).getStartNode().getEntity().compare(edge.getStartNode().getEntity())) == 0){
            if((edges->get(i).getEndNode().getEntity().compare(edge.getEndNode().getEntity())) == 0){
                cout<<"Edges iguales"<<endl;
                edges->get(i).setWeight(120);
                cout<<"Peso arista: "<<edges->get(i).getWeight()<<endl;
                result = true;
                break;
            }
            else{
                continue;
            }
        }
    }
    return result;
}

/*############## ShortestPath class definition ################*/
class ShortestPath {
public:
    ShortestPath();
    ShortestPath(double, TECList<Node<string>> *);
    ~ShortestPath();
    void setPath(TECList<Node<string>> *);
    TECList<Node<string>>* getPath();
    void setDuration(double);
    double getDuration();

private:
    double duration;
    TECList<Node<string>> *path;
};

/*############## ShortestPath class implementation ################*/
ShortestPath::ShortestPath() {
    duration = 0.0;
    path = new TECList<Node<string>>();
}

ShortestPath::ShortestPath(double duration, TECList<Node<string>> *path) {
    this->duration = duration;
    this->path = path;
}

ShortestPath::~ShortestPath() {}

void ShortestPath::setPath(TECList<Node<string>> *path) {
    this->path = path;
}

TECList<Node<string>> * ShortestPath::getPath() {
    return path;
}

void ShortestPath::setDuration(double duration) {
    this->duration = duration;
}

double ShortestPath::getDuration() {
    return duration;
}

/*############## Dijkstra class definition ################*/
class Dijkstra{
public:
    Dijkstra(Graph *);
    ~Dijkstra();
    TECList<Node<string>>* DijkstraShortestPath(Edge path);
    Node<string> closestReachableUnvisited(unordered_map<string, double>);

private:
    Graph *parentGraph;
};

/*############## Dijkstra class implementation ################*/
Dijkstra::Dijkstra(Graph *graph) {
    parentGraph = graph;
}

Dijkstra::~Dijkstra() {}

TECList<Node<string>> * Dijkstra::DijkstraShortestPath(Edge path) {
    TECList<Node<string>> *paths = new TECList<Node<string>>();
    Node<string> start = path.getStartNode();
    Node<string> end = path.getEndNode();
    Node<string> myNull("NULL");
    if (start.getEntity()!=""  && end.getEntity()!=""){
        for(int i=0; i<parentGraph->getNodes()->size(); i++){
            parentGraph->getNodes()->get(i).setVisited(false);
        }
        unordered_map<string, string> changedAt;
        changedAt[start.getEntity()] = myNull.getEntity();
        //changedAt[start.getEntity()] = myNull;
        //changedAt.insert(pair<string, string>(start.getEntity(), myNull.getEntity()));

        unordered_map<string, double> shortestPathMap;
        for(int i=0; i<parentGraph->getNodes()->size(); i++){
            Node<string> node = parentGraph->getNodes()->get(i);
            if(node.getEntity() == start.getEntity()){
                //shortestPathMap[start.getEntity()] = 0.0;
                //shortestPathMap.insert(pair<string, double>(start.getEntity(), 0.0));
                shortestPathMap[start.getEntity()] = 0.0;
            }
            else{
                //shortestPathMap[node.getEntity()] = 1.79769e+308;
                //shortestPathMap.insert(pair<string, double>(node.getEntity(), 12.6897));
                shortestPathMap[node.getEntity()] = 1.79769e+308;
            }
        }

        for(int i=0; i<parentGraph->getEdges()->size(); i++){
            Node<string> s = parentGraph->getEdges()->get(i).getStartNode();
            Node<string> e = parentGraph->getEdges()->get(i).getEndNode();

            if((s.getEntity().compare(start.getEntity())) == 0){
                //shortestPathMap[e.getEntity()] = parentGraph->getEdges()->get(i).getWeight();
                //changedAt[e.getEntity()] = start;
                //shortestPathMap.insert(pair<string, double>(e.getEntity(), parentGraph->getEdges()->get(i).getWeight()));
                shortestPathMap[e.getEntity()] = parentGraph->getEdges()->get(i).getWeight();
                //changedAt.insert(pair<string, string>(e.getEntity(), start.getEntity()));
                changedAt[e.getEntity()] = start.getEntity();
            }
        }
        start.setVisited(true);

        while(true){
            Node<string> currentNode = closestReachableUnvisited(shortestPathMap);
            if((currentNode.getEntity().compare("NULL")) == 0){
                return NULL;
            }

            if((currentNode.getEntity().compare(end.getEntity()))){
                Node<string> child = end;
                //TECList<Node<string>> *paths = new TECList<Node<string>>();
                cout<<"end entity: "<<end.getEntity()<<endl;
                paths->add(end);

                while(true){
                    Node<string> parent(changedAt[child.getEntity()]);
                    if(parent.getEntity().compare("NULL")){
                        break;
                    }
                    cout<<"parent entity: "<<parent.getEntity()<<endl;
                    paths->add(parent);
                    child = parent;
                }
                cout<<"Total weight: "<<shortestPathMap[end.getEntity()]<<endl;
                return paths;
            }
            currentNode.setVisited(true);

            for(int i=0; i<parentGraph->getEdges()->size(); i++){
                Node<string> s = parentGraph->getEdges()->get(i).getStartNode();
                Node<string> e = parentGraph->getEdges()->get(i).getEndNode();
                if(s.getEntity()==currentNode.getEntity()){
                    if(e.isVisited()){
                        continue;
                    }
                    if(shortestPathMap[currentNode.getEntity()] + parentGraph->getEdges()->get(i).getWeight() <
                    shortestPathMap[e.getEntity()]){
                        //shortestPathMap[e.getEntity()] = shortestPathMap[currentNode.getEntity()] + parentGraph->getEdges()->get(i).getWeight();
                        //changedAt[e.getEntity()] = s;
                        //shortestPathMap.insert(pair<string, double>(e.getEntity(), shortestPathMap[currentNode.getEntity()] +
                        //parentGraph->getEdges()->get(i).getWeight()));
                        shortestPathMap[e.getEntity()] = shortestPathMap[currentNode.getEntity()] + parentGraph->getEdges()->get(i).getWeight();

                        changedAt[e.getEntity()] = s.getEntity();
                    }
                }
            }
        }
    }
    cout<<"Error"<<endl;
}

Node<string> Dijkstra::closestReachableUnvisited(unordered_map<string, double> shortestPathMap) {
    double shortestDistance = 1.79769e+308;
    Node<string> closestReachableNode("NULL");
    for(int i=0; i<parentGraph->getNodes()->size(); i++){
        Node<string> node = parentGraph->getNodes()->get(i);
        if(node.isVisited()){
            continue;
        }

        double currentDistance = shortestPathMap[node.getEntity()];
        if(currentDistance == 1.79769e+308){
            continue;
        }

        if(currentDistance < shortestDistance){
            shortestDistance = currentDistance;
            closestReachableNode = node;
        }
    }
    return closestReachableNode;
}

void loadGraph(Graph &);

int main() {
    string n1 = "Maria";
    string n2 = "Maria";
    cout<<"Comparación entre n1 y n2 es: "<<n1.compare(n2)<<endl;
    Node<string> a("Emanuel");
    Node<string> b = a;
    cout<<"Nodo a entity: "<<a.getEntity()<<endl;
    cout<<"Nodo a ID: "<<a.getID()<<endl;
    cout<<"Nodo b entity: "<<b.getEntity()<<endl;
    cout<<"Nodo b ID: "<<b.getID()<<endl;
    Graph graph;
    loadGraph(graph);

    cout<<"Nodes size: "<<graph.getNodes()->size()<<endl;
    cout<<"Edges size: "<<graph.getEdges()->size()<<endl;
    cout<<"\nImprimiendo todos los nodos:"<<endl;
    for(int i=0; i<graph.getNodes()->size(); i++){
        cout<<graph.getNodes()->get(i).getEntity()<<" ";
    }
    cout<<"\n"<<endl;

    cout<<"Imprimieno todas las aristas:"<<endl;
    for(int i=0; i<graph.getEdges()->size(); i++){
        cout<<"start: "<<graph.getEdges()->get(i).getStartNode().getEntity()
        <<", end: "<<graph.getEdges()->get(i).getEndNode().getEntity()<<", weight: "
        <<graph.getEdges()->get(i).getWeight()<<endl;
    }

    Dijkstra dijkstra(&graph);
    Edge vertices;
    cout<<"\nNodos por buscar: ";
    cout<<graph.getNodes()->get(0).getEntity()<<" y ";
    cout<<graph.getNodes()->get(4).getEntity()<<endl;

    vertices.setStartNode(graph.getNodes()->get(0));
    vertices.setEndNode(graph.getNodes()->get(4));
    TECList<Node<string>> *paths = dijkstra.DijkstraShortestPath(vertices);
    cout<<"Path size: "<<paths->size()<<endl;
    cout<<paths->get(0).getEntity()<<endl;
    cout<<paths->get(1).getEntity()<<endl;

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




