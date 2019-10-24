#include "ExtendedResults.h"

ExtendedResults::ExtendedResults(Configuration c, int p) :
	partial(p), Results(c) {
}

string ExtendedResults::getReachConfResults(bool includeVoid) {
	string out = "";
	out += conf.toString();
	out += ((Results)*this).getReachConfResults(includeVoid);
	out += "(total for row & column, including reverse, in this configuration)\n";
	for (int i = 2; i <= partial; i++) {
		int total = conf.getRow(i, false) + conf.getColumn(i, false) + conf.getReverseColumn(i, false) + conf.getReverseRow(i, false);
		out += to_string(i) + " = " + to_string(total) + "\n";
	}
	out += "(total for row & column, including reverse, for all valid turns)\n";
	for (int i = 2; i <= partial; i++) {
		unsigned long long total = solutionFormula(i, false) * 4;
		out += to_string(i) + " = " + to_string(total) + "\n";
	}
	out += "\n\n";
	return out;
}
