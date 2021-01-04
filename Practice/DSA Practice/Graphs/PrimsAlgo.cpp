#define MAX 999999
#include <iostream>
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

public:
    Graph();
    bool isEmpty();
    void insertVertex(char);
    void deleteVertex(char);
    void insertEdge(char, char, int);
    void deleteEdge(char, char);
    void adjacent(char);
    Graph MSTbyPrim();
};
int Graph::getTotalVertices()
{
    int total = 0;
    for (vertex *t = head; t != NULL; t = t->next)
    {
        total++;
    }
    return total;
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
void Graph::adjacent(char value)
{
    cout << "Adjacent of " << value << " = ";
    for (vertex *t = head; t != NULL; t = t->next)
    {
        if (t->vertexValue == value)
        {
            for (edge *w = t->adjList; w != NULL; w = w->nextAdj)
            {
                cout << w->edgeValue << "(" << w->weight << ")"
                     << " ";
            }
            cout << endl;
            break;
        }
    }
}
Graph Graph::MSTbyPrim()
{
    Graph MST;
    bool checker = false;
    int minimum = MAX;
    int numOfEdges = 0;
    vertex *temp1;
    edge *temp2;
    for (vertex *v = head; v != NULL; v = v->next) //get the minimum cost edge from the whole graph
    {
        for (edge *e = v->adjList; e != NULL; e = e->nextAdj)
        {
            if (e->weight < minimum)
            {
                minimum = e->weight;
                temp1 = v;
                temp2 = e;
            }
        }
    }
    MST.insertVertex(temp1->vertexValue); //insert the selected vertices and edges into new graph
    MST.insertVertex(temp2->edgeValue);
    MST.insertEdge(temp1->vertexValue, temp2->edgeValue, minimum);
    numOfEdges++;
    while (numOfEdges != getTotalVertices() - 1) //property of MST
    {
        minimum = MAX;
        for (vertex *v = head; v != NULL; v = v->next)
        {
            if (MST.isVertexPresent(v->vertexValue) == true) //returns true if the vertex v in the graph is also present in the spanning tree,
            {                                                // which means that it can be "selected"
                for (edge *e = v->adjList; e != NULL; e = e->nextAdj)
                {
                    if (e->weight < minimum && MST.isVertexPresent(e->edgeValue) == false) //returns true if the weight of the edge is less than the current minimum
                    {                                                                      // and that vertice is not already present in the spanning tree, since vertices can't be repeated
                        checker = true;
                        minimum = e->weight;
                        temp1 = v;
                        temp2 = e;
                    }
                }
            }
        }
        if (checker == true)
        {
            MST.insertVertex(temp2->edgeValue);
            MST.insertEdge(temp1->vertexValue, temp2->edgeValue, minimum);
            numOfEdges++;
            checker = false;
        }
    }
    return MST;
}
int main()
{
    Graph obj;
    Graph obj2;
    obj.insertVertex('A');
    obj.insertVertex('B');
    obj.insertVertex('C');
    obj.insertVertex('D');
    obj.insertVertex('E');
    obj.insertVertex('F');
    // adding edges according to the given graph
    obj.insertEdge('A', 'B', 7);
    obj.insertEdge('A', 'C', 8);
    obj.insertEdge('B', 'C', 3);
    obj.insertEdge('B', 'D', 6);
    obj.insertEdge('C', 'E', 3);
    obj.insertEdge('C', 'D', 4);
    obj.insertEdge('D', 'E', 2);
    obj.insertEdge('D', 'F', 5);
    obj.insertEdge('E', 'F', 2);
    obj2 = obj.MSTbyPrim();
    obj.adjacent('A'); //displaying adjacent vertices of spanning tree
    obj.adjacent('B');
    obj.adjacent('C');
    obj.adjacent('D');
    obj.adjacent('E');
    obj.adjacent('F');
}