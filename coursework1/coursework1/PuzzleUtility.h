#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

class PuzzleUtility
{
public:
	static vector<int> genRandConf(int num);
	static bool isComposedByNumber(string conf);
};

