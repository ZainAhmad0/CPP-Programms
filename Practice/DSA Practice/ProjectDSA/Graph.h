#define MAX 999999
#include <iostream>
#include <queue>
using namespace std;
struct edge
{
    char edgeValue;
    edge *nextAdj;
    int weight; //weight is introduced for minimum spanning trees algos
};
struct vertex
{
    char vertexValue;
    edge *adjList;
    vertex *next;
};
class Graph
{
private:
    vertex *head;
    int getTotalVertices();
    bool isVertexPresent(char);
    bool isEdgePresent(char, char);
    bool checkCycle();
    vertex *getVertexAdress(char);
    int toDigit(char a);
    bool isAllVerticesPresent(Graph obj);
    string getRoom(char a, int n);

public:
    Graph();
    bool isEmpty();
    void insertVertex(char);
    void deleteVertex(char);
    void insertEdge(char, char, int);
    void deleteEdge(char, char);
    void adjacent(char,int);
    Graph MSTbyKruskals();
    void DijiskrasAlgorithm(char sourceVertex);
    void changeRouteDistances(int n);
    void showRoutes(int n);
};

string Graph ::getRoom(char a, int n)
{
    if (n == 1)
    {
        switch (a)
        {
        case 'A':
            return "Auditorium";
        case 'B':
            return "NC-02";
        case 'C':
            return "XC-01";
        case 'D':
            return "HL-04";
        case 'E':
            return "OC-03";
        default:
            break;
        }
        return " ";
    }
}

void Graph ::showRoutes(int n)
{
    vertex *temp = head;
    while (temp != NULL)
    {
        adjacent(temp->vertexValue,n);
        cout<<endl;
        temp = temp->next;
    }
}

void Graph ::changeRouteDistances(int n)
{
    cout << "Initially The following route distances are defined" << endl<<endl;
    vertex *temp = head;
    edge *edgeTemp = head->adjList;
    showRoutes(n);
    cout << "You are requested to please enter the new route distances " << endl<<endl;
    temp = head;
    int newDist;
    while (temp != NULL)
    {
        edgeTemp = temp->adjList;
        while (edgeTemp != NULL)
        {
            cout << "Current Distance from " << getRoom(temp->vertexValue,n) << " to " << getRoom(edgeTemp->edgeValue,n) << " is " << edgeTemp->weight << endl;
            cout << "Enter New Distance : ";
            cin >> newDist;
            edgeTemp->weight = newDist;
            edgeTemp=edgeTemp->nextAdj;
        }
        cout << endl;
        temp = temp->next;
    }
    cout << "Now the route with changed distances is" << endl<<endl;
    showRoutes(n);
}

bool Graph ::isAllVerticesPresent(Graph obj)
{
    vertex *temp;
    temp = head;
    while (temp != NULL)
    {
        if (!obj.isVertexPresent(temp->vertexValue))
        {
            return false;
        }
        temp = temp->next;
    }
    return true;
}

void Graph::DijiskrasAlgorithm(char sourceVertex = 'A')
{

    // https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
    // I read the pseudo algo from this site and implemented it
    char a = sourceVertex;
    char selectedVertices[getTotalVertices()];
    char parentSource;
    float weight[MAX] = {MAX};
    float tempWeight;
    Graph objTemp;
    int counter = 0;
    edge *temp1;
    for (int i = 0; i < MAX; i++)
    {
        weight[i] = MAX;
    }
    weight[toDigit(sourceVertex)] = 0;
    while (!isAllVerticesPresent(objTemp))
    {
        tempWeight = MAX;
        selectedVertices[counter++] = sourceVertex;
        objTemp.insertVertex(sourceVertex);
        for (edge *temp = getVertexAdress(sourceVertex)->adjList; temp != NULL; temp = temp->nextAdj)
        {
            if (weight[toDigit(sourceVertex)] + temp->weight < weight[toDigit(temp->edgeValue)])
            {
                weight[toDigit(temp->edgeValue)] = weight[toDigit(sourceVertex)] + temp->weight;
            }
        }
        for (int i = 0; i < counter; i++)
        {
            for (edge *temp = getVertexAdress(selectedVertices[i])->adjList; temp != NULL; temp = temp->nextAdj)
            {
                if (weight[toDigit(temp->edgeValue)] < tempWeight && !objTemp.isVertexPresent(temp->edgeValue))
                {
                    temp1 = temp;
                    tempWeight = weight[toDigit(temp->edgeValue)];
                    parentSource = selectedVertices[i];
                }
            }
        }
        sourceVertex = temp1->edgeValue;
    }
    vertex *temp2 = head;
    while (temp2 != NULL)
    {
        cout << a << " - " << temp2->vertexValue << "  =   " << weight[toDigit(temp2->vertexValue)] << endl;
        temp2 = temp2->next;
    }
}

int Graph::getTotalVertices()
{
    int total = 0;
    for (vertex *t = head; t != NULL; t = t->next)
    {
        total++;
    }
    return total;
}

vertex *Graph ::getVertexAdress(char v)
{
    vertex *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->vertexValue == v)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

Graph::Graph()
{
    head = NULL;
}
bool Graph::isEmpty()
{
    return (head == NULL);
}
void Graph::insertVertex(char vertexValue)
{
    if (isEmpty())
    {
        vertex *v = new vertex;
        v->vertexValue = vertexValue;
        v->adjList = NULL;
        v->next = NULL;
        head = v;
        return;
    }
    vertex *temp;
    for (temp = head; temp->next != NULL; temp = temp->next)
        ;
    vertex *v = new vertex;
    v->vertexValue = vertexValue;
    v->adjList = NULL;
    v->next = NULL;
    temp->next = v;
}
void Graph::deleteVertex(char vertexValue)
{
    vertex *p;
    vertex *q;
    edge *r;
    edge *s;
    for (q = 0, p = head; p != NULL; q = p, p = p->next) //traverse downward to find vertex to delete
    {
        if (head->vertexValue == vertexValue) //true if the vertex to be deleted is the first vertex
            head = head->next;
        else if (p->vertexValue == vertexValue)
            q->next = p->next;
        for (s = 0, r = p->adjList; r != NULL; s = r, r = r->nextAdj) //goes into the edges of every vertex and deletes the dges containing the vertexValue
        {
            if (p->adjList->edgeValue == vertexValue) //if edge to be deleted is the first edge
                p->adjList = p->adjList->nextAdj;
            else if (r->edgeValue == vertexValue)
                s->nextAdj = r->nextAdj;
        }
    }
}
void Graph::insertEdge(char vertexValue1, char vertexValue2, int w)
{
    vertex *vIterator1;
    for (vIterator1 = head; vIterator1->vertexValue != vertexValue1; vIterator1 = vIterator1->next)
        ;                                        //traverses downward to find vertexValue1
    if (vIterator1->vertexValue == vertexValue1) //true is vertexValue1 found
    {
        if (vIterator1->adjList == NULL) //true if vertexValue1 has no edges yet
        {
            edge *e = new edge; //insert vertexValue2 as edge of vertexValue1
            e->edgeValue = vertexValue2;
            e->nextAdj = NULL;
            e->weight = w;
            vIterator1->adjList = e;
        }
        else
        {
            edge *eIterator1;
            for (eIterator1 = vIterator1->adjList; eIterator1->nextAdj != NULL; eIterator1 = eIterator1->nextAdj)
                ;
            edge *e = new edge;
            e->edgeValue = vertexValue2;
            e->nextAdj = NULL;
            e->weight = w;
            eIterator1->nextAdj = e;
        }
    }
    vertex *vIterator2;
    for (vIterator2 = head; vIterator2->vertexValue != vertexValue2; vIterator2 = vIterator2->next)
        ;                                        //traverses downward to find vertexValue2
    if (vIterator2->vertexValue == vertexValue2) //true if vertexValue2 is found
    {
        if (vIterator2->adjList == NULL) //true is vertexValue2 has no edges yet
        {
            edge *e = new edge; //insert vertexValue2 as edge of vertexvalue1
            e->edgeValue = vertexValue1;
            e->nextAdj = NULL;
            e->weight = w;
            vIterator2->adjList = e;
        }
        else
        {
            edge *eIterator2;
            for (eIterator2 = vIterator2->adjList; eIterator2->nextAdj != NULL; eIterator2 = eIterator2->nextAdj)
                ;
            edge *e = new edge;
            e->edgeValue = vertexValue1;
            e->nextAdj = NULL;
            e->weight = w;
            eIterator2->nextAdj = e;
        }
    }
}
void Graph::deleteEdge(char value1, char value2)
{
    vertex *p;
    edge *q;
    edge *r;
    for (p = head; p != NULL; p = p->next) //traverse downward to find value1
    {
        if (p->vertexValue == value1)
        {
            for (r = 0, q = p->adjList; q != NULL; r = q, q = q->nextAdj) //traverses through the edges of value1
            {
                if (p->adjList->edgeValue == value2) //true if edge to be deleted is the first
                    p->adjList = p->adjList->nextAdj;
                if (q->edgeValue == value2)
                    r->nextAdj = q->nextAdj;
            }
        }
    }
    for (p = head; p != NULL; p = p->next) //traverse downward to find value2
    {
        if (p->vertexValue == value2)
        {
            for (r = 0, q = p->adjList; q != NULL; r = q, q = q->nextAdj) //traverse through the edges of value2
            {
                if (p->adjList->edgeValue == value1) //true if the edge to be deleted is the first
                    p->adjList = p->adjList->nextAdj;
                else if (q->edgeValue == value1)
                    r->nextAdj = q->nextAdj;
            }
        }
    }
}
void Graph::adjacent(char value, int n)
{
    if (n == 1)
    {
        
        cout << "Adjacent of " << getRoom(value,n) << " = ";
        for (vertex *t = head; t != NULL; t = t->next)
        {
            if (t->vertexValue == value)
            {
                for (edge *w = t->adjList; w != NULL; w = w->nextAdj)
                {
                    cout << getRoom(w->edgeValue,n) << "(" << w->weight << "), "
                         << " ";
                }
                cout << endl;
                break;
            }
        }
    }
}

bool Graph::isVertexPresent(char value)
{
    for (vertex *v = head; v != NULL; v = v->next)
    {
        if (v->vertexValue == value)
            return true;
    }
    return false;
}

bool Graph ::isEdgePresent(char vertexValue, char edgeValue)
{
    for (vertex *v = head; v != NULL; v = v->next)
    {
        if (v->vertexValue == vertexValue)
        {
            for (edge *e = v->adjList; e != NULL; e = e->nextAdj)
            {
                if (e->edgeValue == edgeValue)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int Graph ::toDigit(char a)
{
    return (a - '0');
}

bool Graph ::checkCycle() // cycles are detected in the graph by using BFS, DFS. i am using BFS
{
    int count = 0;
    bool checker = true;
    queue<char> queueObj;
    char *arr = new char[getTotalVertices()];
    int parent[MAX] = {-1}; //this tells the parent of every node, they are all initialized with -1. because at the start, all nodes are their own parents
    queueObj.push(head->vertexValue);
    arr[count++] = head->vertexValue;
    while (!queueObj.empty())
    {
        char tempVertex = queueObj.front();
        queueObj.pop();
        vertex *temp = getVertexAdress(tempVertex);
        edge *tempEdge = temp->adjList;
        while (tempEdge != NULL)
        {
            for (int i = 0; i < count; i++)
            {
                if (arr[i] == tempEdge->edgeValue)                          //For every visited vertex 'v', if there is an adjacent 'e' such that 'e' is already
                {                                                           //visited and 'e' is not parent of 'v', then there is a cycle in graph
                    if (parent[tempVertex] != toDigit(tempEdge->edgeValue)) //returns true if the current adjacent vertice 'e' is the parent of vertice
                    {                                                       // 'v' which means that a cycle is being formed
                        return true;
                    }
                    checker = false;
                    break;
                }
            }
            if (checker)
            {
                queueObj.push(tempEdge->edgeValue);
                parent[tempEdge->edgeValue] = toDigit(tempVertex); //sets the current vertice 'v' as the parent of the current adjacent vertice 'e'
                arr[count++] = tempEdge->edgeValue;
            }
            checker = true;
            tempEdge = tempEdge->nextAdj;
        }
    }
    return false;
}

Graph Graph::MSTbyKruskals()
{
    Graph MST;
    Graph tempObj; // this obj is used to check discarded edges that makes cycle
    bool checker = false;
    int minimum = MAX;
    int numOfEdges = 0;
    vertex *temp1;
    edge *temp2;
    while (numOfEdges != getTotalVertices() - 1) //property of MST
    {
        minimum = MAX;
        for (vertex *v = head; v != NULL; v = v->next)
        {
            for (edge *e = v->adjList; e != NULL; e = e->nextAdj)
            {
                if (e->weight < minimum) //returns true if the weight of the edge is less than the current minimum
                {
                    if (!tempObj.isEdgePresent(v->vertexValue, e->edgeValue))
                    {
                        minimum = e->weight;
                        temp1 = v;
                        temp2 = e;
                    }
                }
            }
        }
        if (!MST.isVertexPresent(temp1->vertexValue))
        {
            MST.insertVertex(temp1->vertexValue);
            tempObj.insertVertex(temp1->vertexValue);
        }
        if (!MST.isVertexPresent(temp2->edgeValue))
        {
            MST.insertVertex(temp2->edgeValue);
            tempObj.insertVertex(temp2->edgeValue);
        }
        MST.insertEdge(temp1->vertexValue, temp2->edgeValue, minimum);
        tempObj.insertEdge(temp1->vertexValue, temp2->edgeValue, minimum);
        if (MST.checkCycle()) // check whether the shortest that we have added is making cycle or not. If it is making cycle it would delete the edge else it would continue.
        {
            MST.deleteEdge(temp1->vertexValue, temp2->edgeValue);
            continue;
        }
        numOfEdges++;
    }
    return MST;
}