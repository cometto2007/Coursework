#pragma once

class Configuration
{
public:
	Configuration(int* nums, int size);
	Configuration(int size);
	~Configuration();
	int* getTable() const;
	void setTable(int* nums);
	int test();
private:
	int* table;
	int rowSize;
	int totalSize;
	bool isFinal();
	int getVoidTile();
	int* getAvailableMoves();
	void swapTiles(int index1, int index2);
	int makePermutations();
};

