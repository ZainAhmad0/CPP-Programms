
bool Graph::isCyclic(char start) //cycles are detected in the graph by using BFS
{
	int parent[getTotalVertices()] = {-1}; //this tells the parent of every node, they are all initialized with -1
	int counter = 0;					   //because at the start, all nodes are their own parents
	int visitCheck = 0;
	char visited[getTotalVertices()];
	Queue obj(getTotalVertices());
	obj.insert(start);
	visited[counter] = start;
	counter++;
	while (!obj.isEmpty())	{
		char v = obj.remove();
		vertex *temp = getNode(v);
		for (edge *e = temp->adjList; e != NULL; e = e->nextAdj)
		{
			for (int i = 0; i < counter; i++)
			{
				if (visited[i] == e->edgeValue) //For every visited vertex 'v', if there is an adjacent 'e' such that 'e' is already
				{								//visited and 'e' is not parent of 'v', then there is a cycle in graph
					visitCheck++;
					if (parent[getNum(v)] != getNum(e->edgeValue)) //returns true if the current adjacent vertice 'e' is the parent of vertice
						return true;							   // 'v' which means that a cycle is being formed
				}
			}
			if (visitCheck == 0)
			{
				obj.insert(e->edgeValue);
				visited[counter] = e->edgeValue;
				counter++;
				parent[getNum(e->edgeValue)] = getNum(v); //sets the current vertice 'v' as the parent of the current adjacent vertice 'e'
			}
			visitCheck = 0;
		}
	}
	return false;
}

int Graph::getNum(char ch)
{
	char temp = 'A';
	for (int i = 1; i <= 26; i++)
	{
		if (temp == ch)
			return i;
		temp++;
	}
	return temp;
}
