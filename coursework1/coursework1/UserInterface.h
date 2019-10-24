#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include <regex> 
#include "PuzzleUtility.h"
#include "Configuration.h"
#include "FileManager.h"

using namespace std;

class UserInterface
{
public:
	static int getMainTask(int puzzleSize);
	static vector<int> getUserConfiguration(int puzzleSize);
	static vector<vector<int>> generateRandomConfs(int puzzleSize);
	static int getResultMenuTask();
	static void printOnScreen(string res);
	static void printOnFile(FileManager* fm, string res) throw (invalid_argument);
	static vector<vector<int>> getConfsFromFile(FileManager* fm, int puzzleSize) throw (invalid_argument);
	static bool runProgAgain();
	static int choosePuzzleSize();
	static int getPartialNum();
	static bool getIncludeVoid();
private:
	static bool checkForYNInput();
	static bool isValidFileName(string fileName);
	static bool validateConf(vector<vector<int>>& confs);
};
