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
    objEE.insertVertex('A');
    objEE.insertVertex('B');
    objEE.insertVertex('C');
    objEE.insertVertex('D');
    objEE.insertVertex('E');
    // adding edges according to the given graph
    objEE.insertEdge('A', 'B', 4);
    objEE.insertEdge('A', 'C', 9);
    objEE.insertEdge('A', 'D', 2);
    objEE.insertEdge('A', 'E', 12);
    objEE.insertEdge('B', 'C', 10);
    objEE.insertEdge('B', 'E', 6);
    objEE.insertEdge('E', 'D', 5);
    objEE.insertEdge('D', 'C', 3);
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
        newObj.showRoutes(1);
    }
    else if (n == 2)
    {
        Graph newObj = objSE.MSTbyKruskals();
        newObj.showRoutes(1);
    }
    else if (n == 3)
    {
        Graph newObj = objCE.MSTbyKruskals();
        newObj.showRoutes(1);
    }
    else if (n == 4)
    {
        Graph newObj = objCE.MSTbyKruskals();
        newObj.showRoutes(1);
    }
    return;
}

void GraphManager ::showShortestRouteToEachLocation(int n)
{
    if (n == 1)
    {
        objEE.DijiskrasAlgorithm();
    }
    else if (n == 2)
    {
        objSE.DijiskrasAlgorithm();
    }
    else if (n == 3)
    {
        objCE.DijiskrasAlgorithm();
    }
    else if (n == 4)
    {
        objCS.DijiskrasAlgorithm();
    }
    return;
}