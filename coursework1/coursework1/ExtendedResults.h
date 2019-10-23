#pragma once
#include "Results.h"
class ExtendedResults :
	public Results {

public:
	ExtendedResults(Configuration c, int p);
	string getReachConfResults(bool includeVoid) override;
private:
	int partial;
};
