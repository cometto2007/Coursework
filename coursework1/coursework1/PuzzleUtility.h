#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "Configuration.h"

using namespace std;

class PuzzleUtility
{
public:
	static vector<vector<int>> genRandConfs(int numConf, int puzzleSize);
	static bool isComposedByNumber(string conf);
	static string getResult(vector<int> conf, int partial);
	static string getExtendedResults(vector<vector<int>> confs, int partial);
	static string getTotalRowsColumnsRes(vector<int> conf, int partial);
	static string getResults(vector<vector<int>> confs, int partial);
	static string printConfs(vector<vector<int>> confs);
	static string printConf(vector<int> conf);
};

