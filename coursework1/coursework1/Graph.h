#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct Edge
{
	int src, dest, label;
};

typedef pair<int, int> Pair;

class Graph
{
public:
	Graph(vector<Edge>& edges, int n);
	void printGraph();
	void addEdge(Edge& e);
	bool edgeExist(Edge& e);
	bool edgeExist(int src, int dest, int label);
private:
	vector<vector<Pair>> adjList;
};

