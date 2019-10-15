#include <iostream>
#include "Graph.h"
#include "Configuration.h"

int main()
{
	vector<Edge> edges;
	Graph graph(edges, 6);

	Edge e = { 0, 1, 6 };
	Edge e1 = { 0, 1, 7 };
	graph.addEdge(e);
	graph.addEdge(e1);

	graph.printGraph();

	cout << graph.edgeExist(0, 1, 8);

	return 0;
}