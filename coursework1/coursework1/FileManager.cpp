#include "FileManager.h"

FileManager::FileManager(string puzzles, string confs) :
	puzzlesFile(puzzles), solFile(confs)
{
}

void FileManager::printConfs(vector<vector<int>> confs, unsigned int mode)
{
	ofstream outfile;
	outfile.open(puzzlesFile, mode);

	outfile << confs.size() << "\n";
	outfile << PuzzleUtility::printConfs(confs);

	outfile.close();
}

void FileManager::printResults(string res, unsigned int mode)
{
	ofstream outfile;
	outfile.open(solFile, mode);
	outfile << res;
	outfile.close();
}

vector<vector<int>> FileManager::getConfs(int puzzleSize)
{
	vector<vector<int>> confs;
	vector<int> conf;

	ifstream inFile;
	inFile.open(puzzlesFile);
	string output;
	if (inFile.is_open()) {
		inFile >> output;
		while (!inFile.eof()) {
			inFile >> output;
			conf.push_back(stoi(output));
			if (puzzleSize == conf.size()) {
				conf.push_back(0);
				confs.push_back(conf);
				conf.clear();
			}
		}
	}
	inFile.close();
	return confs;
}
