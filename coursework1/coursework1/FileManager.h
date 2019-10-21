#pragma once
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include "PuzzleUtility.h"

using namespace std;

class FileManager
{
public:
	FileManager(string puzzles, string confs);
	void printConfs(vector<vector<int>> confs, unsigned int mode);
	void printResults(vector<vector<int>> confs, unsigned int mode);
	vector<vector<int>> getConfs(int puzzleSize);
private:	
	string puzzlesFile;
	string solFile;

	string printConf(vector<int> conf);
};

