#include <iostream>
#include <sstream>
#include <set>
#include "UserInterface.h"
#include "PuzzleUtility.h"
#include "FileManager.h"
#include "Configuration.h"

using namespace std;

void handleResultsDelivery(int task, FileManager* const fm, int puzzleSize) {
	int partial = (int)sqrt(puzzleSize + 1);
	vector<vector<int>> confs = UserInterface::getConfsFromFile(fm, puzzleSize);
	bool includeVoid = false;
	string res;

	switch (task) {
	case 1:
		includeVoid = UserInterface::getIncludeVoid();
		res = PuzzleUtility::getResults(confs, partial, false, includeVoid);
		UserInterface::printOnScreen(res);
		UserInterface::printOnFile(fm, res);
		break;
	case 2:
		partial = UserInterface::getPartialNum();
		res = PuzzleUtility::getResults(confs, partial, true, false);
		UserInterface::printOnScreen(res);
		UserInterface::printOnFile(fm, res);
		break;
	case 3:
		res = PuzzleUtility::getExtendedResults(confs, partial);
		UserInterface::printOnScreen(res);
		UserInterface::printOnFile(fm, res);
		break;
	default:
		break;
	}
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
