#include <iostream>
#include <sstream>
#include <set>
#include "UserInterface.h"
#include "PuzzleUtility.h"
#include "FileManager.h"
#include "Configuration.h"

using namespace std;

void handleResultsDelivery(int task, FileManager* const fm, int puzzleSize) {
	int partial = 0;
	vector<vector<int>> confs = UserInterface::getConfsFromFile(fm, puzzleSize);
	bool includeVoid = false;
	string res;

	switch (task) {
	case 1:
		includeVoid = UserInterface::getIncludeVoid();
		res = PuzzleUtility::getResults(confs, 0, false, includeVoid);
		break;

	case 2:
		partial = UserInterface::getPartialNum();
		res = PuzzleUtility::getResults(confs, partial, false, includeVoid);
		break;
	case 3:
		res = PuzzleUtility::getResults(confs, 0, true, false);
		break;
	case 4:
		partial = UserInterface::getPartialNum();
		res = PuzzleUtility::getResults(confs, partial, true, false);
		break;
	case 5:
		res = PuzzleUtility::getExtendedResults(confs, (int)sqrt(puzzleSize + 1));
		break;
	default:
		break;
	}
	UserInterface::printOnScreen(res);
	UserInterface::printOnFile(fm, res);
}

int main()
{
	FileManager* fm = FileManager::getInstance();
	int puzzleSize = UserInterface::choosePuzzleSize();

	vector<vector<int>> confs(0);
	bool execute = true;

	while (execute) {
		int task = UserInterface::getMainTask(puzzleSize);

		switch (task) {
		case 1:
			confs.push_back(UserInterface::getUserConfiguration(puzzleSize));
			UserInterface::printOnFile(fm, PuzzleUtility::printConfs(confs));
			break;

		case 2:
			confs = UserInterface::generateRandomConfs(puzzleSize);
			UserInterface::printOnFile(fm, PuzzleUtility::printConfs(confs));
			break;

		case 3:
			handleResultsDelivery(UserInterface::getResultMenuTask(), fm, puzzleSize);
			break;

		default:
			break;
		}
		execute = UserInterface::runProgAgain();
		confs.clear();
	}
	
	return 0;
}
