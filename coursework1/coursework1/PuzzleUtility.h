#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Configuration.h"
#include "Results.h"
#include "ExtendedResults.h"

using namespace std;

class PuzzleUtility
{
public:
	static vector<vector<int>> genRandConfs(int numConf, int puzzleSize);
	static bool isComposedByNumber(string conf);
	static string getExtendedResults(vector<vector<int>> confs, int partial, bool includeVoid);
	static string getResults(vector<vector<int>> confs, int partial, bool confsReach, bool includeVoid);
	static string printConfs(vector<vector<int>> confs);
	static string printConf(vector<int> conf);
private:
	static void genRandConf(int i, vector<vector<int>>& confs, int puzzleSize);
};

