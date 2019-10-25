#include "ExtendedResults.h"

ExtendedResults::ExtendedResults(Configuration c, int p) :
	partial(p), Results(c) {
}

string ExtendedResults::getReachConfResults(int partial) {
	string out = "";
	out += conf.toString();
	out += ((Results)*this).getReachConfResults(0);
	out += "(total for row & column, including reverse, in this configuration)\n";
	for (int i = 2; i <= partial; i++) {
		int total = conf.getRow(i) + conf.getColumn(i) + conf.getReverseColumn(i) + conf.getReverseRow(i);
		out += to_string(i) + " = " + to_string(total) + "\n";
	}
	out += "(total for row & column, including reverse, for all valid turns)\n";
	for (int i = 2; i <= partial; i++) {
		InfInt total = partialSolutionFormula(i) * 4;
		out += to_string(i) + " = " + total.toString() + "\n";
	}
	out += "\n\n";
	return out;
}
