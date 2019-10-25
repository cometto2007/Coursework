#pragma once
#include "Results.h"
class ExtendedResults :
	public Results {

public:
	ExtendedResults(Configuration c, int p);
	string getReachConfResults(int partial) override;
private:
	int partial;
};
