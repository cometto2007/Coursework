#pragma once
#include <string>
#include "Configuration.h"

class Results {
protected:
	Configuration conf;
	unsigned long long solutionFormula(int partial, bool includeVoid);
public:
	Results(Configuration c);
	string getConfResults();
	virtual string getReachConfResults(bool includeVoid);
private:
	unsigned long long factorial(int n);
};

