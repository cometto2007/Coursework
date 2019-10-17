#include "Arch.h"

Arch::Arch() :
	src(0), dest(0), label(-1)
{
	confs = vector<vector<int>>(0);
}

Arch::Arch(const Arch& a) :
	src(a.src), dest(a.dest), label(a.label), confs(a.confs)
{
}

Arch::Arch(int src, int dest, int label, vector<int> conf) :
	src(src), dest(dest), label(label)
{
	confs = vector<vector<int>>(0);
	confs.push_back(conf);
}

Arch::~Arch()
{
	for (rsize_t i = 0; i < confs.size(); i++) {
		confs[i].clear();
	}
	confs.clear();
}

int Arch::getDest()
{
	return dest;
}

int Arch::getLabel()
{
	return label;
}

int Arch::getSource()
{
	return src;
}

void Arch::addConf(vector<int> conf)
{
	confs.push_back(conf);
}

vector<vector<int>> Arch::getConf()
{
	return confs;
}

bool Arch::confIsPresent(vector<int> conf)
{
	for (vector<int> c : confs) {
		if (c == conf) {
			return true;
		}
	}
	return false;
}
