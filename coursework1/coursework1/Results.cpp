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

string Results::getReachConfResults(bool includeVoid) {
	string res = "";
	int partial = conf.getTable().size();
	unsigned long long n = solutionFormula(partial, includeVoid);

	res += "row = " + to_string(n) + "\n";
	res += "column = " + to_string(n) + "\n";
	res += "reverse row = " + to_string(n) + "\n";
	res += "reverse column = " + to_string(n) + "\n";
	return res;
}

unsigned long long Results::solutionFormula(int partial, bool includeVoid) {
	int rowSize = conf.getTable().size();
	int pos = rowSize * rowSize - 1 - partial;
	Configuration c(rowSize);
	int freq = c.getRow(partial, includeVoid);
	int contOccurr = conf.getContinuousOccurrence(partial);

	unsigned long long res = freq * (factorial(pos) / 2) * contOccurr;
	if (includeVoid) {
		contOccurr = conf.getContinuousOccurrence(partial - 1);
		res += (factorial(pos + 1) / 2)* contOccurr;
	}
	return res;
	
}

unsigned long long Results::factorial(int n) {
	if (n > 1) {
		return factorial(n - 1) * n;
	} else {
		return 1;
	}
}

