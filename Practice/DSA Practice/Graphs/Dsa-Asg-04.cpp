
//DSA Assignment No 4
// Graph Implementation
/*
To:
Sir Adeel
By:
1 - Zain Ahmad (01-131192-037)
2 - Mirza Haris (01-131192-019)
3 - Ahmed Shahzad Qayani (01-131192-003)
Dated: 29/11/2020
*/

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
    bool isEmpty();
    Edge<A> *Adjacent(A vertex); // to show the adjacent edges of the vertex
};

template <class A>
Graph<A>::Graph()
{
    head->edgeHead = NULL;
    head->nextVertex = NULL;
    head = NULL;
}

template <class A>
Edge<A> *Graph<A>::Adjacent(A vertex) // would return the list head of the edges
{
    for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
    {
        if (temp->vertex == vertex)
        {
            return temp->edgeHead;
        }
    }
    return NULL;
}

template <class A>
bool Graph<A>::isEmpty()
{
    return (head == NULL);
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
bool Graph<A>::insertEdge(A vertexOne, A vertexTwo)
{
    // edge from vertex-one to vertex-two would be added as well from vertex-two to vertex-one would also be added
    bool flag = false;
    for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
    {
        if (temp->vertex == vertexOne || temp->vertex == vertexTwo)
        {
            A vertex;
            if (temp->vertex == vertexOne)
            {
                vertex = vertexTwo;
            }
            else
            {
                vertex = vertexOne;
            }
            /* the above if else condition is implemented to add the edges from vertex1 to vertex2 as well as from vertex2 to vertex1*/
            if (temp->edgeHead == NULL)
            {
                Edge<A> *tempEdge = new Edge<A>;
                tempEdge->next = NULL;
                tempEdge->vertex = vertex;
                temp->edgeHead = tempEdge;
                flag = true;
                continue;
            }
            else
            {
                Edge<A> *tempEdge, *tempEdge1;
                tempEdge1 = temp->edgeHead;

                for (tempEdge = temp->edgeHead; tempEdge != NULL; tempEdge = tempEdge->next)
                {
                    if (tempEdge->vertex == vertex)
                    {
                        return true; // as this edge is already there in edge list so no need to duplicate the edge
                    }
                    tempEdge1 = tempEdge;
                }
                Edge<A> *newEdge = new Edge<A>;
                newEdge->vertex = vertex;
                newEdge->next = NULL;
                tempEdge1->next = newEdge;
                flag = true;
                continue;
            }
        }
    }
    return flag;
}

template <class A>
bool Graph<A>::deleteVertex(A vertex)
{
    bool flag = false;
    VertexNode<A> *temp1;
    temp1 = head;
    for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
    {
        if (temp->vertex == vertex)
        {
            if (temp == head)
            {
                head = temp->nextVertex;
            }
            else
            {
                temp1->nextVertex = temp->nextVertex;
            }
            delete temp;
            // now as the vertex is deleted i am now deleting all edges associated with that vertex
            for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
            {
                if (temp->edgeHead == NULL)
                {
                    continue;
                }
                else
                {
                    Edge<A> *tempEdge1 = temp->edgeHead;
                    Edge<A> *tempEdge;
                    for (tempEdge = temp->edgeHead; tempEdge != NULL; tempEdge = tempEdge->next)
                    {
                        if (tempEdge->vertex == vertex)
                        {
                            if (tempEdge == temp->edgeHead)
                            {
                                temp->edgeHead = tempEdge->next;
                            }
                            else
                            {
                                tempEdge1->next = tempEdge->next;
                            }
                            delete tempEdge;
                            break;
                        }
                        tempEdge1 = tempEdge;
                    }
                }
            }
            flag = true;
            break; // as the vertex and all the edges associated with this vertex is successfully deleted so breaking the loop
        }
        temp1 = temp;
    }
    return flag;
}

template <class A>
bool Graph<A>::deleteEdge(A vertexOne, A vertexTwo)
{
    bool flag = false;
    // edge from both the vertices would be deleted
    for (VertexNode<A> *temp = head; temp != NULL; temp = temp->nextVertex)
    {
        if (temp->vertex == vertexOne || temp->vertex == vertexTwo)
        {
            A vertex;
            if (temp->vertex == vertexOne)
            {
                vertex = vertexTwo;
            }
            else
            {
                vertex = vertexOne;
            }
            Edge<A> *tempEdge1 = temp->edgeHead;
            Edge<A> *tempEdge;
            for (tempEdge = temp->edgeHead; tempEdge != NULL; tempEdge = tempEdge->next)
            {
                if (tempEdge->vertex == vertex)
                {
                    if (tempEdge == temp->edgeHead)
                    {
                        temp->edgeHead = tempEdge->next;
                    }
                    else
                    {
                        tempEdge1->next = tempEdge->next;
                    }
                    delete tempEdge;
                    flag = true;
                    break;
                }
                tempEdge1 = tempEdge;
            }
        }
    }
    return flag;
}

int main()
{
    Graph<char> obj;
    Edge<char> *edgeHead; // for displaying the list of edges
    // adding vertices
    obj.insertVertex('A');
    obj.insertVertex('B');
    obj.insertVertex('C');
    obj.insertVertex('D');
    obj.insertVertex('E');
    // adding edges according to the given graph
    obj.insertEdge('A', 'C');
    obj.insertEdge('A', 'B');
    obj.insertEdge('A', 'E');
    obj.insertEdge('B', 'A');
    obj.insertEdge('B', 'C');
    obj.insertEdge('B', 'E');
    obj.insertEdge('B', 'D');
    obj.insertEdge('D', 'B');
    obj.insertEdge('D', 'E');
    obj.insertEdge('C', 'B');
    obj.insertEdge('C', 'A');
    obj.insertEdge('E', 'D');
    obj.insertEdge('E', 'B');
    obj.insertEdge('E', 'A');
    // now displaying adjacent edges of the every particular vertices for checking that our graph is implemented correctly
    edgeHead = obj.Adjacent('A');
    cout << "Adjacent edges of vertex A -> ";
    while (edgeHead != NULL)
    {
        cout << edgeHead->vertex << ", ";
        edgeHead = edgeHead->next;
    }
    cout << endl;
    edgeHead = obj.Adjacent('B');
    cout << "Adjacent edges of vertex B -> ";
    while (edgeHead != NULL)
    {
        cout << edgeHead->vertex << ", ";
        edgeHead = edgeHead->next;
    }
    cout << endl;
    edgeHead = obj.Adjacent('C');
    cout << "Adjacent edges of vertex C -> ";
    while (edgeHead != NULL)
    {
        cout << edgeHead->vertex << ", ";
        edgeHead = edgeHead->next;
    }
    cout << endl;
    edgeHead = obj.Adjacent('D');
    cout << "Adjacent edges of vertex D -> ";
    while (edgeHead != NULL)
    {
        cout << edgeHead->vertex << ", ";
        edgeHead = edgeHead->next;
    }
    cout << endl;
    edgeHead = obj.Adjacent('E');
    cout << "Adjacent edges of vertex E -> ";
    while (edgeHead != NULL)
    {
        cout << edgeHead->vertex << ", ";
        edgeHead = edgeHead->next;
    }
    cout << endl;
    return 0;
}