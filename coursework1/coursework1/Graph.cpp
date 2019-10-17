#include "Graph.h"

Graph::Graph(vector<Arch>& arches, int n)
{
	adjList.resize(n);

	for (Arch& arch: arches) {
		addArch(arch.getSource(), arch.getDest(), arch.getLabel());
	}
}

Graph::Graph(const Graph& src)
{
	adjList.resize(src.adjList.size());
	setList(src.adjList);
}

void Graph::setList(vector<vector<Arch>> newAdjList)
{
	adjList = newAdjList;
}

void Graph::printGraph()
{
	for (rsize_t i = 0; i < adjList.size(); i++)
	{
		for (Arch arch : adjList[i])
			cout << "(" << i << ", " << arch.getDest() <<
			", " << arch.getLabel() << ") ";
		cout << endl;
	}
}

void Graph::addConf(int src, int dest, int label, vector<int> conf)
{
	if (!ArchExist(src, dest, label)) {
		addArch(src, dest, label);
	}
	Arch* foundArch = getArch(src, dest, label);
	if (!confExist(conf, *foundArch)) {
		foundArch->addConf(conf);
	}
}

void Graph::addArch(int src, int dest, int label)
{
	adjList[src].push_back(Arch(src, dest, label, vector<int>(0)));
}

bool Graph::confExist(vector<int> conf, Arch arch)
{
	return arch.confIsPresent(conf);
}

bool Graph::ArchExist(int src, int dest, int label)
{
	for (Arch a : adjList[src]) {
		if (a.getSource() == src &&
			a.getDest() == dest &&
			a.getLabel() == label) {
			return true;
		}
	}
	return false;
}

Arch* Graph::getArch(int src, int dest, int label) {
	for (rsize_t i = 0; i < adjList[src].size(); i++) {
		Arch* arch = &(adjList[src][i]);
		if (src == arch->getSource() &&
			dest == arch->getDest() &&
			label == arch->getLabel()) {
			return arch;
		}
	}
	return nullptr;
}
