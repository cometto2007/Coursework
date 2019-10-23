#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct Coord {
	int x;
	int y;
};

class Configuration
{
public:
	Configuration(vector<vector<int>> nums, int size);
	Configuration(vector<int> nums);
	Configuration(int size);
	Configuration(const Configuration& src);
	~Configuration();
	vector<vector<int>> getTable() const;
	vector<int> getTableAsVector() const;
	void setTable(vector<vector<int>> newTable);
	bool isFinal();
	Coord getVoidTile();
	vector<Coord> getAvailableMoves();
	void swapTiles(Coord c1, Coord c2);
	string toString();
	int getRow(int partial);
	int getColumn(int partial);
	int getReverseRow(int partial);
	int getReverseColumn(int partial);
	int getContinuousOccurrence(int partial);
	static vector<vector<int>> convertVectorToTable(vector<int> nums);
private:
	vector<vector<int>> table;
	bool isContinuous(vector<int> v);
	bool isReverseContinuous(vector<int> v);
};

