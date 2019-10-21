#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

class PuzzleUtility
{
public:
	static vector<vector<int>> genRandConfs(int numConf, int numNumbers);
	static bool isComposedByNumber(string conf);
	static string getResults(vector<int> conf);
};

