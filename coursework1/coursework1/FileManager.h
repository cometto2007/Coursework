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
	static FileManager* getInstance();
	void printConfs(vector<vector<int>> confs, string fileName, unsigned int mode);
	void printResults(string res, string fileName, unsigned int mode);
	vector<vector<int>> getConfs(int puzzleSize, string fileName);
private:
	FileManager();
};

