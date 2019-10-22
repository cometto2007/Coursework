#include <iostream>
#include <sstream>
#include <set>
#include "UserInterface.h"
#include "PuzzleUtility.h"
#include "FileManager.h"
#include "Configuration.h"

using namespace std;

void handleResultsDelivery(int task, FileManager& fm, int puzzleSize) {
	int partial = UserInterface::getPartialNum();
	string res;

	switch (task) {
	case 1:
		res = PuzzleUtility::getResults(fm.getConfs(puzzleSize), partial);
		if (UserInterface::printOnScreen()) {
			cout << res;
		}
		if (UserInterface::printOnFile()) {
			fm.printResults(res, ofstream::out);
		}
		break;
	case 2:
		res = PuzzleUtility::getExtendedResults(fm.getConfs(puzzleSize), partial);
		if (UserInterface::printOnScreen()) {
			cout << res;
		}
		if (UserInterface::printOnFile()) {
			fm.printResults(res, ofstream::out);
		}
		break;
	case 3:
		break;
	default:
		break;
	}
}

int main()
{
	FileManager fm("15-File.txt", "Solution-File.txt");
	int puzzleSize = UserInterface::choosePuzzleSize();

	vector<vector<int>> confs(0);
	bool execute = true;

	while (execute) {
		int task = UserInterface::getMainTask(puzzleSize);

		switch (task) {
		case 1:
			confs.push_back(UserInterface::getUserConfiguration(puzzleSize));
			if (UserInterface::printOnFile()) {
				fm.printConfs(confs, ofstream::out);
			}
			break;

		case 2:
			confs = UserInterface::generateRandomConfs(puzzleSize);
			if (UserInterface::printOnFile()) {
				fm.printConfs(confs, ofstream::out);
			}
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

/*int main() {
	vector<int> v(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);
	v.push_back(9);
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(15);
	v.push_back(14);
	v.push_back(13);
	v.push_back(0);

	Configuration c(v);
	c.print();
	cout << c.getColumn(4) << "\n";
	cout << c.getReverseColumn(4) << "\n";
	cout << c.getRow(4) << "\n";
	cout << c.getReverseRow(4) << "\n";

	vector<Coord> v1 = c.getAvailableMoves();
	return 0;
}*/
