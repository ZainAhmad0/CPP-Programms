#include <iostream>
using namespace std;

template <class B>
struct Edge
{
    B vertex;
    Edge<B> *next;
};

template <class A>
struct VertexNode
{
    Edge<A> *edgeHead;
    A vertex;
    VertexNode *nextVertex;
};

template <class A>
class Graph
{
private:
    VertexNode<A> *head;

public:
    Graph();
    void insertVertex(A vertex);
    bool insertEdge(A vertex1, A vertex2); // this would return true if the both the vertices exists otherwise false
    bool deleteVertex(A vertex);           // this would return true if the vertex exists otherwise false
    bool deleteEdge(A vertex1, A vertex2); // this would return true if the both the vertices exists and the edge between them exists otherwise false
};
template <class A>
Graph<A>::Graph()
{
    head->edgeHead = NULL;
    head->nextVertex = NULL;
    head = NULL;
}

template <class A>
void Graph<A>::insertVertex(A vertex)
{
    if (head == NULL)
    {
        VertexNode<A> *newNodeVertex = new VertexNode<A>();
        newNodeVertex->vertex = vertex;
        newNodeVertex->nextVertex = NULL;
        head = newNodeVertex;
    }
    else
    {
        VertexNode<A> *temp = head;
        while (temp->nextVertex != NULL)
        {
            temp = temp->nextVertex;
        }
        VertexNode<A> *newNodeVertex = new VertexNode<A>();
        newNodeVertex->vertex = vertex;
        newNodeVertex->nextVertex = NULL;
        temp->nextVertex = newNodeVertex;
    }
}

template <class A>
bool Graph<A>::insertEdge(A vertex1, A vertex2)
{
    // edge from vertex1 to vertex2 would be added as well from vertex2 to vertex 1 would also be added
    bool flag = false;
    for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
    {
        if (temp->vertex == vertex1) // this if condition would add edge from vertex1 to vertex2
        {
            if (temp->edgeHead == NULL)
            {
                Edge<A> *tempEdge = new Edge<A>;
                tempEdge->next = NULL;
                tempEdge->vertex = vertex2;
                temp->edgeHead = tempEdge;
                flag = true;
                continue;
            }
            else
            {
                Edge<A> *tempEdge;
                for (tempEdge = temp->edgeHead; tempEdge->next != NULL; tempEdge = tempEdge->next)
                {
                    if (tempEdge->vertex == vertex2)
                    {
                        return true; // as this edge is already there in edge list so no need to duplicate the edge
                    }
                }
                Edge<A> *newEdge = new Edge<A>;
                newEdge->vertex = vertex2;
                newEdge->next = NULL;
                tempEdge->next = newEdge;
                flag = true;
                continue;
            }
        }
        if (temp->vertex == vertex2)// this if condition would add edge from vertex2 to vertex1
        {
            if (temp->edgeHead == NULL)
            {
                Edge<A> *tempEdge = new Edge<A>;
                tempEdge->next = NULL;
                tempEdge->vertex = vertex1;
                temp->edgeHead = tempEdge;
                flag = true;
                continue;
            }
            else
            {
                Edge<A> *tempEdge;
                for (tempEdge = temp->edgeHead; tempEdge->next != NULL; tempEdge = tempEdge->next)
                {
                    if (tempEdge->vertex == vertex1)
                    {
                        return true; // as this edge is already there in edge list so no need to duplicate the edge
                    }
                }
                Edge<A> *newEdge = new Edge<A>;
                newEdge->vertex = vertex1;
                newEdge->next = NULL;
                tempEdge->next = newEdge;
                flag = true;
                continue;
            }
        }
    }
    return flag;
}

bool deleteVertex(A vertex);

int main()
{
    Graph<char> obj;
    obj.insertVertex('A');
    obj.insertVertex('B');
    obj.insertVertex('C');
    obj.insertVertex('D');
    if (obj.insertEdge('A', 'B'))
        cout << "Added" << endl;
    return 0;
}