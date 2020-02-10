#include "PuzzleUtility.h"
#include <random>
#include <chrono>
#include <algorithm>
#include <thread>

vector<vector<int>> PuzzleUtility::genRandConfs(int numConf, int puzzleSize)
{
	int numtask1, numtask2;
	if (numConf % 2 == 0) {
		numtask1 = numtask2 = numConf / 2;
	} else {
		numtask1 = numConf / 2;
		numtask2 = numConf / 2 + 1;
	}
	vector<vector<int>> confs1(numtask1);
	vector<vector<int>> confs2(numtask2);
	thread t1 = thread(genRandConf, ref(confs1), puzzleSize);
	thread t2 = thread(genRandConf, ref(confs2), puzzleSize);

	t1.join();
	t2.join();

	vector<vector<int>> confs;
	confs.reserve(confs1.size() + confs2.size());
	confs.insert(confs.end(), confs1.begin(), confs1.end());
	confs.insert(confs.end(), confs2.begin(), confs2.end());

	return confs;
}

// Slower version without Threads
/*vector<vector<int>> PuzzleUtility::genRandConfs(int numConf, int puzzleSize)
{
	vector<vector<int>> confs(numConf);
	genRandConf(confs, puzzleSize);
	

	return confs;
}*/

void PuzzleUtility::genRandConf(vector<vector<int>>& confs, int puzzleSize) {
	for (size_t i = 0; i < confs.size(); i++) {
		time_t  seed = chrono::system_clock::now().time_since_epoch().count();
		std::default_random_engine e((unsigned int)seed);

		vector<int> conf(0);
		for (int i = 1; i <= (puzzleSize + 5); i++) {
			conf.push_back(i);
		}
		shuffle(conf.begin(), conf.end(), e);
		conf = vector<int>(conf.begin(), conf.begin() + puzzleSize);
		conf.push_back(0);
		confs[i] = conf;
	}
}

bool PuzzleUtility::isComposedByNumber(string conf)
{
	string::const_iterator it = conf.begin();
	while (it != conf.end() && (std::isdigit(*it) || *it == ' ')) {
		++it;
	}
	return !conf.empty() && it == conf.end();
}

string PuzzleUtility::getExtendedResults(vector<vector<int>> confs, int partial) {
	string out = "";

	out += to_string(confs.size()) + "\n";
	for (vector<int> conf : confs) {
		Configuration c(conf);
		ExtendedResults r(c, partial);
		out += r.getReachConfResults(partial);
		out += "\n\n";
	}
	return out;
}

string PuzzleUtility::getResults(vector<vector<int>> confs, int partial, bool confsReach, bool includeVoid) {
	string out = "";
	out += to_string(confs.size()) + "\n";
	for (vector<int> conf : confs) {
		Configuration c(conf);
		Results r(c);
		out += c.toString();
		
		if (confsReach) {
			out += r.getReachConfResults(partial);
		} else {
			out += r.getConfResults(includeVoid, partial);
		}
		
		out += "\n\n";
	}
	return out;
}

string PuzzleUtility::printConfs(vector<vector<int>> confs) {
	string out = "";
	out += to_string(confs.size()) + "\n";
	for (vector<int> conf : confs) {
		out += printConf(conf);
		out += "\n\n";
	}
	return out;
}

string PuzzleUtility::printConf(vector<int> conf) {
	string res = "";
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
