#include "PuzzleUtility.h"

vector<vector<int>> PuzzleUtility::genRandConfs(int numConf, int numNumbers)
{
	vector<vector<int>> confs;
	vector<int> conf(0);
	for (int i = 1; i <= numNumbers; i++) {
		conf.push_back(i);
	}

	for (int i = 0; i < numConf; i++) {
		random_shuffle(conf.begin(), conf.end());
		conf = vector<int>(conf.begin(), conf.begin() + 15);
		conf.push_back(0);

		confs.push_back(conf);
		conf.pop_back();
	}
	
	return confs;
}

bool PuzzleUtility::isComposedByNumber(string conf)
{
	string::const_iterator it = conf.begin();
	while (it != conf.end() && (std::isdigit(*it) || *it == ' ')) {
		++it;
	}
	return !conf.empty() && it == conf.end();
}

string PuzzleUtility::getResults(vector<int> conf)
{
	string res = "";
	res += "row = 2302\n";
	res += "column = 2344\n";
	res += "reverse row = 2341\n";
	res += "reverse column = 2341\n";
	return res;
}
