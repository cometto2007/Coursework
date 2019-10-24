#include "Results.h"

Results::Results(Configuration c) : conf(c) {
}

string Results::getConfResults(bool includeVoid) {
	string res = "";

	int partial = conf.getTable().size();
	res += "row = " + to_string(conf.getRow(partial, includeVoid)) + "\n";
	res += "column = " + to_string(conf.getColumn(partial, includeVoid)) + "\n";
	res += "reverse row = " + to_string(conf.getReverseRow(partial, includeVoid)) + "\n";
	res += "reverse column = " + to_string(conf.getReverseColumn(partial, includeVoid)) + "\n";
	return res;
}

string Results::getReachConfResults() {
	string res = "";
	int partial = conf.getTable().size();
	unsigned long long n = solutionFormula();

	res += "row = " + to_string(n) + "\n";
	res += "column = " + to_string(n) + "\n";
	res += "reverse row = " + to_string(n) + "\n";
	res += "reverse column = " + to_string(n) + "\n";
	return res;
}

unsigned long long Results::solutionFormula() {
	int rowSize = conf.getTable().size();
	unsigned long long res = partialSolutionFormula(rowSize);

	int contOccurr = conf.getContinuousOccurrence(rowSize - 1);
	res += (factorial(rowSize * rowSize - rowSize) / 2)* contOccurr;
	return res;
}

unsigned long long Results::partialSolutionFormula(int partial) {
	int rowSize = conf.getTable().size();
	int pos = rowSize * rowSize - 1 - partial;
	Configuration c(rowSize);
	int freq = c.getRow(partial);
	int contOccurr = conf.getContinuousOccurrence(partial);

	return freq * (factorial(pos) / 2) * contOccurr;
}

unsigned long long Results::factorial(int n) {
	if (n > 1) {
		return factorial(n - 1) * n;
	} else {
		return 1;
	}
}

