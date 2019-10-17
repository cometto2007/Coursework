#pragma once
#include<vector>

using namespace std;

class Arch
{
private:
	int src;
	int dest;
	int label;
	vector<vector<int>> confs;

public:
	Arch();
	Arch(const Arch& a);
	Arch(int src, int dest, int label, vector<int> conf);
	~Arch();
	int getDest();
	int getLabel();
	int getSource();
	void addConf(vector<int> conf);
	vector<vector<int>> getConf();
	bool confIsPresent(vector<int> conf);
};

