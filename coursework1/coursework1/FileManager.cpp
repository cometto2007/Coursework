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
	for (vector<int> conf : confs) {
		outfile << printConf(conf);
		outfile << "\n\n";
	}
	outfile.close();
}

void FileManager::printResults(vector<vector<int>> confs, unsigned int mode)
{
	ofstream outfile;
	outfile.open(solFile, mode);

	outfile << confs.size() << "\n";
	for (vector<int> conf : confs) {
		outfile << printConf(conf);
		outfile << PuzzleUtility::getResults(conf);
		outfile << "\n\n";
	}
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
				confs.push_back(conf);
				conf.clear();
			}
		}
	}
	inFile.close();
	return confs;
}

string FileManager::printConf(vector<int> conf)
{
	string res = "\n";
	int rowSize = (int)sqrt(conf.size());
	for (rsize_t i = 0; i < conf.size(); i++) {
		if (conf[i] != 0) {
			res.append(to_string(conf[i]) + "\t");
		}
		if ((i + 1 >= (unsigned int)rowSize) && ((i + 1) % rowSize) == 0) {
			res.append("\n");
		}
	}
	return res;
}
