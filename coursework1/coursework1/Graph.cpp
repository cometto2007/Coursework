#include "Graph.h"

Graph::Graph(vector<Edge>& edges, int n)
{
	adjList.resize(n);

	for (Edge& edge: edges) {
		addEdge(edge);
	}
}

void Graph::printGraph()
{
	for (int i = 0; i < adjList.size(); i++)
	{
		for (Pair v : adjList[i])
			cout << "(" << i << ", " << v.first <<
			", " << v.second << ") ";
		cout << endl;
	}
}

void Graph::addEdge(Edge& e)
{
	int src = e.src;
	int dest = e.dest;
	int label = e.label;

	adjList[src].push_back(make_pair(dest, label));
}

bool Graph::edgeExist(Edge& e)
{
	return edgeExist(e.src, e.dest, e.label);
}

bool Graph::edgeExist(int src, int dest, int label)
{
	std::vector<Pair>::iterator it = std::find(adjList[src].begin(), adjList[src].end(), make_pair(dest, label));
	return it != adjList[src].end();
}
