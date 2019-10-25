#pragma once
#include <string>
#include "Configuration.h"
#include "InfInt.h"


class Results {
protected:
	Configuration conf;
	InfInt solutionFormula();
	InfInt partialSolutionFormula(int partial);
public:
	Results(Configuration c);
	string getConfResults(bool includeVoid, int partial);
	virtual string getReachConfResults(int partial);
private:
	InfInt factorial(int n);
};

