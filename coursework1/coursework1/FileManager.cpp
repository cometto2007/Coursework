#include "FileManager.h"

FileManager::FileManager()
{
}

FileManager* FileManager::getInstance() {
	static FileManager fm;
	return &fm;
}

void FileManager::printConfs(vector<vector<int>> confs, string fileName, unsigned int mode)
{
	ofstream outfile;
	outfile.open(fileName, mode);

	if (outfile.fail()) {
		throw invalid_argument("no file exists named " + fileName);
	}
		
	outfile << confs.size() << "\n";
	outfile << PuzzleUtility::printConfs(confs);

	outfile.close();
}

void FileManager::printResults(string res, string fileName, unsigned int mode)
{
	ofstream outfile;
	outfile.open(fileName, mode);
	if (outfile.fail()) {
		throw invalid_argument("no file exists named " + fileName);
	}
	outfile << res;
	outfile.close();
}

vector<vector<int>> FileManager::getConfs(int puzzleSize, string fileName)
{
	vector<vector<int>> confs;
	vector<int> conf;

	ifstream inFile;
	inFile.open(fileName);
	if (inFile.fail()) {
		throw invalid_argument("no file exists named " + fileName);
	}
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
