#include "PuzzleUtility.h"

vector<int> PuzzleUtility::genRandConf(int num)
{
	vector<int> conf(0);
	for (int i = 1; i <= num; i++) {
		conf.push_back(i);
	}
	random_shuffle(conf.begin(), conf.end());
	conf = vector<int>(conf.begin(), conf.begin() + 15);
	conf.push_back(0);

	return conf;
}

bool PuzzleUtility::isComposedByNumber(string conf)
{
	string::const_iterator it = conf.begin();
	while (it != conf.end() && (std::isdigit(*it) || *it == ' ')) {
		++it;
	}
	return !conf.empty() && it == conf.end();
}
