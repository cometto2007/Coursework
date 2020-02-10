#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>

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
	vector<vector<int>> Table() const;
	vector<int> getTableAsVector() const;
	void setTable(vector<vector<int>> newTable);
	bool isFinal();
	void swapTiles(Coord c1, Coord c2);
	string toString();
	int getRow(int partial, bool voidTile = false) const;
	int getColumn(int partial, bool voidTile = false) const;
	int getReverseRow(int partial, bool voidTile = false) const;
	int getReverseColumn(int partial, bool voidTile = false) const;
	int getContinuousOccurrence(int partial) const;
	bool isValid() const;
	static vector<vector<int>> convertVectorToTable(vector<int> nums);
private:
	vector<vector<int>> table;
	bool isContinuous(vector<int> v, bool voidTile = false) const;
	bool isReverseContinuous(vector<int> v, bool voidTile = false) const;
};

