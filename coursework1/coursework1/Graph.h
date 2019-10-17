#pragma once
#include <vector>
#include <iostream>
#include "Arch.h"

using namespace std;

class Graph
{
public:
	Graph(vector<Arch>& arches, int n);
	Graph(const Graph& src);
	void setList(vector<vector<Arch>> adjList);
	void printGraph();
	void addConf(int src, int dest, int label, vector<int> conf);
	void addArch(int src, int dest, int label);
	Arch* getArch(int src, int dest, int label);
	bool confExist(vector<int> conf, Arch arch);
	bool ArchExist(int src, int dest, int label);
private:
	vector<vector<Arch>> adjList;
};

