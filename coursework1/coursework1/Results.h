#pragma once
#include <string>
#include "Configuration.h"
#include "InfInt.h"


class Results {
protected:
	Configuration conf;
	InfInt solutionFormula() const;
	InfInt partialSolutionFormula(int partial) const;
public:
	Results(Configuration c);
	string getConfResults(bool includeVoid, int partial) const;
	virtual string getReachConfResults(int partial);
private:
	InfInt factorial(int n) const;
};

