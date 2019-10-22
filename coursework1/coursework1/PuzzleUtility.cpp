#include "PuzzleUtility.h"

vector<vector<int>> PuzzleUtility::genRandConfs(int numConf, int puzzleSize)
{
	vector<vector<int>> confs;
	vector<int> conf(0);
	for (int i = 1; i <= (puzzleSize + 5); i++) {
		conf.push_back(i);
	}

	for (int i = 0; i < numConf; i++) {
		random_shuffle(conf.begin(), conf.end());
		conf = vector<int>(conf.begin(), conf.begin() + puzzleSize);
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

string PuzzleUtility::getResult(vector<int> conf, int partial)
{
	string res = "";

	Configuration c(conf);
	res += "row = " + to_string(c.getRow(partial)) + "\n";
	res += "column = " + to_string(c.getColumn(partial)) + "\n";
	res += "reverse row = " + to_string(c.getReverseRow(partial)) + "\n";
	res += "reverse column = " + to_string(c.getReverseColumn(partial)) + "\n";
	return res;
}

string PuzzleUtility::getExtendedResults(vector<vector<int>> confs, int partial) {
	string out = "";
	out += to_string(confs.size()) + "\n";
	for (vector<int> conf : confs) {
		out += PuzzleUtility::printConf(conf);
		out += PuzzleUtility::getResult(conf, partial);
		out += PuzzleUtility::getTotalRowsColumnsRes(conf, partial);
		out += "\n\n";
	}
	return out;
}

string PuzzleUtility::getTotalRowsColumnsRes(vector<int> conf, int partial) {
	Configuration c(conf);

	string out = "(total for row & column, including reverse, in this configuration)\n";
	for (int i = 2; i <= partial; i++) {
		int total = c.getRow(i);
		total += c.getColumn(i);
		total += c.getReverseRow(i);
		total += c.getReverseColumn(i);
		out += to_string(i) + " = " + to_string(total) + "\n";
	}
	return out;
}

string PuzzleUtility::getResults(vector<vector<int>> confs, int partial) {
	string out = "";
	out += to_string(confs.size()) + "\n";
	for (vector<int> conf : confs) {
		out += PuzzleUtility::printConf(conf);
		out += PuzzleUtility::getResult(conf, partial);
		out += "\n\n";
	}
	return out;
}

string PuzzleUtility::printConfs(vector<vector<int>> confs) {
	string out = "";
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
