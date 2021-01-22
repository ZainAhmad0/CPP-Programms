#include <iostream>
#include <string>
#include "Graph.h"
#include <fstream>
using namespace std;

class GraphManager
{
private:
    Graph objEE, objSE, objCE, objCS;

public:
    GraphManager();
    void changeRoute(int n);
    void showRoute(int n);
    void showShortestRouteToEachLocation(int n);
};
GraphManager ::GraphManager()
{
    // ADDING VERTICES TO EE GRAPH
    objEE.insertVertex('A');
    objEE.insertVertex('B');
    objEE.insertVertex('C');
    objEE.insertVertex('D');
    objEE.insertVertex('E');
    // ADDING VERTICES TO SE
    objSE.insertVertex('A');
    objSE.insertVertex('B');
    objSE.insertVertex('C');
    objSE.insertVertex('D');
    objSE.insertVertex('E');
    // ADDING VERTICES TO EE GRAPH
    objCE.insertVertex('A');
    objCE.insertVertex('B');
    objCE.insertVertex('C');
    objCE.insertVertex('D');
    objCE.insertVertex('E');
    // ADDING VERTICES TO SE
    objCS.insertVertex('A');
    objCS.insertVertex('B');
    objCS.insertVertex('C');
    objCS.insertVertex('D');
    objCS.insertVertex('E');
    // adding edges according to the EE graph
    objEE.insertEdge('A', 'B', 4);
    objEE.insertEdge('A', 'C', 9);
    objEE.insertEdge('A', 'D', 2);
    objEE.insertEdge('A', 'E', 12);
    objEE.insertEdge('B', 'C', 10);
    objEE.insertEdge('B', 'E', 6);
    objEE.insertEdge('E', 'D', 5);
    objEE.insertEdge('D', 'C', 3);
    // adding edges according to the SE graph
    objSE.insertEdge('A', 'B', 9);
    objSE.insertEdge('A', 'C', 14);
    objSE.insertEdge('A', 'D', 7);
    objSE.insertEdge('A', 'E', 4);
    objSE.insertEdge('B', 'C', 12);
    objSE.insertEdge('B', 'E', 3);
    objSE.insertEdge('E', 'D', 10);
    objSE.insertEdge('D', 'C', 8);
    // adding edges according to the CE graph
    objCE.insertEdge('A', 'B', 11);
    objCE.insertEdge('A', 'C', 12);
    objCE.insertEdge('A', 'D', 19);
    objCE.insertEdge('A', 'E', 3);
    objCE.insertEdge('B', 'C', 10);
    objCE.insertEdge('B', 'E', 9);
    objCE.insertEdge('E', 'D', 2);
    objCE.insertEdge('D', 'C', 13);
    // adding edges according to the CS graph
    objCS.insertEdge('A', 'B', 4);
    objCS.insertEdge('A', 'C', 3);
    objCS.insertEdge('A', 'D', 26);
    objCS.insertEdge('A', 'E', 4);
    objCS.insertEdge('B', 'C', 20);
    objCS.insertEdge('B', 'E', 7);
    objCS.insertEdge('E', 'D', 5);
    objCS.insertEdge('D', 'C', 10);
}

void GraphManager ::changeRoute(int n)
{
    if (n == 1)
    {
        objEE.changeRouteDistances(1);
    }
    else if (n == 2)
    {
        objSE.changeRouteDistances(2);
    }
    else if (n == 3)
    {
        objCE.changeRouteDistances(3);
    }
    else if (n == 4)
    {
        objCS.changeRouteDistances(4);
    }
    return;
}

void GraphManager ::showRoute(int n)
{
    if (n == 1)
    {
        Graph newObj = objEE.MSTbyKruskals();
        newObj.showRoutes(n);
    }
    else if (n == 2)
    {
        objSE.showRoutes(2);
        // Graph newObj1 = objSE.MSTbyKruskals();
        // newObj1.showRoutes(n);
    }
    else if (n == 3)
    {
        Graph newObj2 = objCE.MSTbyKruskals();
        newObj2.showRoutes(n);
    }
    else if (n == 4)
    {
        
        Graph newObj3 = objCS.MSTbyKruskals();
        newObj3.showRoutes(n);
    }
    return;
}

void GraphManager ::showShortestRouteToEachLocation(int n)
{
    if (n == 1)
    {
        objEE.DijiskrasAlgorithm(n);
    }
    else if (n == 2)
    {
        objSE.DijiskrasAlgorithm(n);
    }
    else if (n == 3)
    {
        objCE.DijiskrasAlgorithm(n);
    }
    else if (n == 4)
    {
        objCS.DijiskrasAlgorithm(n);
    }
    cout << endl;
    return;
}