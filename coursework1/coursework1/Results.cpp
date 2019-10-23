#include "Results.h"

Results::Results(Configuration c) : conf(c) {
}

string Results::getConfResults() {
	string res = "";

	int partial = conf.getTable().size();
	res += "row = " + to_string(conf.getRow(partial)) + "\n";
	res += "column = " + to_string(conf.getColumn(partial)) + "\n";
	res += "reverse row = " + to_string(conf.getReverseRow(partial)) + "\n";
	res += "reverse column = " + to_string(conf.getReverseColumn(partial)) + "\n";
	return res;
}

string Results::getReachConfResults(bool includeVoid) {
	string res = "";
	int partial = conf.getTable().size();
	int n = solutionFormula(partial, includeVoid);

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
	int freq = c.getRow(rowSize);
	int contOccurr = conf.getContinuousOccurrence(partial);

	int res = freq * (factorial(pos) / 2) * contOccurr;
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

