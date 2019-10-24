#pragma once
#include <string>
#include "Configuration.h"

class Results {
protected:
	Configuration conf;
	unsigned long long solutionFormula();
	unsigned long long partialSolutionFormula(int partial);
public:
	Results(Configuration c);
	string getConfResults(bool includeVoid);
	virtual string getReachConfResults();
private:
	unsigned long long factorial(int n);
};

