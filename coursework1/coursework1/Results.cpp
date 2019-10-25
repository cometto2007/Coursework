#include "Results.h"

Results::Results(Configuration c) : conf(c) {
}

string Results::getConfResults(bool includeVoid, int partial) {
	string res = "";

	if (partial == 0) {
		partial = conf.getTable().size();
	}
	res += "row = " + to_string(conf.getRow(partial, includeVoid)) + "\n";
	res += "column = " + to_string(conf.getColumn(partial, includeVoid)) + "\n";
	res += "reverse row = " + to_string(conf.getReverseRow(partial, includeVoid)) + "\n";
	res += "reverse column = " + to_string(conf.getReverseColumn(partial, includeVoid)) + "\n";
	return res;
}

string Results::getReachConfResults(int partial) {
	string res = "";
	InfInt n;
	if (partial == 0) {
		n = solutionFormula();
	} else {
		n = partialSolutionFormula(partial);
	}
	
	res += "row = " + n.toString() + "\n";
	res += "column = " + n.toString() + "\n";
	res += "reverse row = " + n.toString() + "\n";
	res += "reverse column = " + n.toString() + "\n";
	return res;
}

InfInt Results::solutionFormula() {
	int rowSize = conf.getTable().size();
	InfInt res = partialSolutionFormula(rowSize);

	int contOccurr = conf.getContinuousOccurrence(rowSize - 1);
	res += (factorial(rowSize * rowSize - rowSize) / 2)* contOccurr;
	return res;
}

InfInt Results::partialSolutionFormula(int partial) {
	int rowSize = conf.getTable().size();
	int pos = rowSize * rowSize - 1 - partial;
	Configuration c(rowSize);
	InfInt freq = c.getRow(partial);
	int contOccurr = conf.getContinuousOccurrence(partial);

	return freq * (factorial(pos) / 2) * contOccurr;
}

InfInt Results::factorial(int n) {
	if (n > 1) {
		return factorial(n - 1) * n;
	} else {
		return 1;
	}
}

