/* this code is implemented correct but in linux it displays
segmentation fault but when I run it in online cpp compiler or
in windows it runs perfectly fine
29 Nov 2020 (I ran it on linux ubuntu)
*/

#include <iostream>
#include <queue>
#include <stack>
#include <list>
using namespace std;

template <class B>
struct Edge
{
    B vertex;
    float weight;
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
    int getTotalVertices();
    VertexNode<A> *getVertexAdress(A vertex);
    Edge<A> *getSmallestDistantEdge(A vertex);

public:
    Graph();
    void insertVertex(A vertex);
    bool insertEdge(A vertex1, A vertex2, float edgeWeight); // this would return true if the both the vertices exists otherwise false
    bool deleteVertex(A vertex);                             // this would return true if the vertex exists otherwise false
    bool deleteEdge(A vertex1, A vertex2);                   // this would return true if the both the vertices exists and the edge between them exists otherwise false
    bool isEmpty();                                          // check wheter the graph is empty or not - contains any vertex or not
    Edge<A> *Adjacent(A vertex);                             // return the edge head of all the adjacent vertices of a prticular vertex
    list<A> breathFirstSearch(A vertex);                     // uses queue
    void depthFirstSearch(A vertex);                      // uses stack for backtracking
    Graph getMSTByPrimsAlgorithm(A vertex);                  // uses prims algortim to get the minimum spanning tree
    Graph getMSTByKruskalsAlgorithm(A vertex);               // uses kruskals algortim to get the minimum spanning tree
};

template <class A>
Graph<A>::Graph()
{
    head->edgeHead = NULL;
    head->nextVertex = NULL;
    head = NULL;
}

template <class A>
Edge<A> *Graph<A>::getSmallestDistantEdge(A vertex)
{
    Edge<A> *temp = getVertexAdress(vertex)->edgeHead;
    Edge<A> *temp1 = temp;
    while (temp1 != NULL)
    {
        if (temp1->weight < temp->weight)
        {
            temp = temp1;
        }
        temp1->next;
    }
    return temp;
}

template <class A>
Graph<A> Graph<A>::getMSTByPrimsAlgorithm(A vertex) // uses prims algortim to get the minimum spanning tree
{
    Graph<A> obj;
    A *arr = new A[getTotalVertices()];
    int counter = 0;
    while (counter < getTotalVertices())
    {
    }
}

template <class A>
Graph<A> Graph<A>::getMSTByKruskalsAlgorithm(A vertex) // uses kruskals algortim to get the minimum spanning tree
{
}

template <class A>
void Graph<A>::depthFirstSearch(A vertex)
{
    int count = 0;
    bool checker = true;
    stack<A> stackObj;
    A *arr = new A[getTotalVertices()];
    stackObj.push(vertex);
    cout << vertex << ", ";;
    arr[count++] = vertex;
    while (!stackObj.empty())
    {
        A tempVertex = stackObj.top();
        VertexNode<A> *temp = getVertexAdress(tempVertex);
        Edge<A> *tempEdge = temp->edgeHead;
        while (tempEdge != NULL)
        {
            for (int i = 0; i < count; i++)
            {
                if (arr[i] == tempEdge->vertex)
                {
                    checker = false;
                    break;
                }
            }
            if (checker)
            {
                stackObj.push(tempEdge->vertex);
                cout << tempEdge->vertex << ", ";
                arr[count++] = tempEdge->vertex;
                break;
            }
            else if (tempEdge->next == NULL && !checker)
            {
                stackObj.pop();
            }
            checker = true;
            tempEdge = tempEdge->next;
        }
    }
    cout << endl;
}

template <class A>
list<A> Graph<A>::breathFirstSearch(A vertex)
{
    int count = 0;
    bool checker = true;
    list<A> objList; // this is for returning the list of vertexes that make bfs
    queue<A> queueObj;
    A *arr = new A[getTotalVertices()];
    queueObj.push(vertex);
    arr[count++] = vertex;
    while (!queueObj.empty())
    {
        A tempVertex = queueObj.front();
        queueObj.pop();
        VertexNode<A> *temp = getVertexAdress(tempVertex);
        objList.push_back(tempVertex);
        Edge<A> *tempEdge = temp->edgeHead;
        while (tempEdge != NULL)
        {
            for (int i = 0; i < count; i++)
            {
                if (arr[i] == tempEdge->vertex)
                {
                    checker = false;
                    break;
                }
            }
            if (checker)
            {
                queueObj.push(tempEdge->vertex);
                arr[count++] = tempEdge->vertex;
            }
            checker = true;
            tempEdge = tempEdge->next;
        }
    }
    return objList;
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
bool Graph<A>::insertEdge(A vertexOne, A vertexTwo, float edgeWeight)
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
                tempEdge->weight = edgeWeight;
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
                newEdge->weight = edgeWeight;
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

template <class A>
int Graph<A>::getTotalVertices()
{
    VertexNode<A> *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        temp = temp->nextVertex;
        i++;
    }
    return i;
}

template <class A>
VertexNode<A> *Graph<A>::getVertexAdress(A vertex)
{
    VertexNode<A> *temp = head;
    while (temp != NULL)
    {
        if (temp->vertex == vertex)
        {
            return temp;
        }
        temp = temp->nextVertex;
    }
    return NULL;
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
    obj.insertVertex('F');
    // adding edges according to the given graph
    obj.insertEdge('A', 'B', 7);
    obj.insertEdge('A', 'C', 8);
    obj.insertEdge('B', 'A', 7);
    obj.insertEdge('B', 'C', 3);
    obj.insertEdge('B', 'D', 6);
    obj.insertEdge('C', 'A', 8);
    obj.insertEdge('C', 'B', 3);
    obj.insertEdge('C', 'E', 3);
    obj.insertEdge('C', 'D', 4);
    obj.insertEdge('D', 'B', 6);
    obj.insertEdge('D', 'C', 4);
    obj.insertEdge('D', 'E', 2);
    obj.insertEdge('D', 'F', 5);
    obj.insertEdge('E', 'C', 3);
    obj.insertEdge('E', 'D', 2);
    obj.insertEdge('E', 'F', 2);
    obj.insertEdge('F', 'D', 5);
    obj.insertEdge('F', 'E', 2);
    // now displaying adjacent edges of the every particular vertices for checking that our graph is implemented correctly
    list<char> objList = obj.breathFirstSearch('A');
    int size = objList.size();
    for (int i = 0; i < size; i++)
    {
        cout << objList.front() << ", ";
        objList.pop_front();
    }
    cout << endl;
    list<char> objList = obj.depthFirstSearch('A');
    // size = objList1.size();
    // for (int i = 0; i < size; i++)
    // {
    //     cout << objList1.front() << ", ";
    //     objList1.pop_front();
    // }
    // edgeHead = obj.Adjacent('A');
    // cout << "Adjacent edges of vertex A -> ";
    // float weight;
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // edgeHead = obj.Adjacent('B');
    // cout << "Adjacent edges of vertex B -> ";
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // edgeHead = obj.Adjacent('C');
    // cout << "Adjacent edges of vertex C -> ";
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // edgeHead = obj.Adjacent('D');
    // cout << "Adjacent edges of vertex D -> ";
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // edgeHead = obj.Adjacent('E');
    // cout << "Adjacent edges of vertex E -> ";
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // edgeHead = obj.Adjacent('F');
    // cout << "Adjacent edges of vertex F -> ";
    // while (edgeHead != NULL)
    // {
    //     cout << edgeHead->vertex << " & ";
    //     cout << edgeHead->weight << " , ";
    //     edgeHead = edgeHead->next;
    // }
    // cout << endl;
    // return 0;
}