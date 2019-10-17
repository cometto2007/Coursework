#pragma once
#include "Graph.h"

class Configuration
{
public:
	Configuration(vector<int> nums, int size);
	Configuration(int size);
	Configuration(const Configuration& src);
	~Configuration();
	vector<int> getTable() const;
	void setTable(vector<int> nums);
	bool isFinal();
	int getVoidTile();
	int* getAvailableMoves();
	void swapTiles(int index1, int index2);
	void print();

private:
	vector<int> table;
	int rowSize;
	int totalSize;
};

