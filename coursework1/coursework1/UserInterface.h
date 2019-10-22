#pragma once
#include <iostream>
#include <sstream>
#include <set>
#include "PuzzleUtility.h"
#include "Configuration.h"

using namespace std;

class UserInterface
{
public:
	static int getMainTask(int puzzleSize);
	static vector<int> getUserConfiguration(int puzzleSize);
	static vector<vector<int>> generateRandomConfs(int puzzleSize);
	static int getResultMenuTask();
	static bool printOnScreen();
	static bool printOnFile();
	static bool runProgAgain();
	static int choosePuzzleSize();
	static int getPartialNum();
};

