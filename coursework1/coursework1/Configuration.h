#pragma once
#include "Graph.h"

class Configuration
{
public:
	Configuration(int* nums, int size);
	Configuration(int size);
	Configuration(const Configuration& src);
	~Configuration();
	int* getTable() const;
	void setTable(int* nums);
	bool isFinal();
	int getVoidTile();
	int* getAvailableMoves();
	void swapTiles(int index1, int index2);
	void print();

private:
	int* table;
	int rowSize;
	int totalSize;
};

