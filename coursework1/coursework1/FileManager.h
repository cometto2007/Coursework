#pragma once
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class FileManager
{
public:
	FileManager();
	void printConfs(vector<vector<int>> confs);
private:
	ofstream outfile;
};

