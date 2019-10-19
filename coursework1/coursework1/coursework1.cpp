#include <iostream>
#include <sstream>
#include <set>
#include "UserInterface.h"
#include "PuzzleUtility.h"
#include "FileManager.h"


using namespace std;

int getTask() {
	int choice = 0;

	UserInterface::printMainMenu();
	cin >> choice;

	while (choice < 1 || choice > 3) {
		UserInterface::printWrongInputError();
		cin >> choice;
	}

	return choice;
}

void insertConfiguration() {
	string numbers = "";
	UserInterface::printInsertConfigurationSection();

	cin.ignore();
	cin.clear();
	getline(cin, numbers);

	if (PuzzleUtility::isComposedByNumber(numbers)) {
		stringstream ss(numbers);

		set<int> set;

		for (int i = 0; ss >> i; ) {
			if (i && i > 0 && i <= 20) {
				set.insert(i);
			}
		}
		if (set.size() != 15) {
			UserInterface::printWrongInputError();
		}
	}
	else {
		UserInterface::printWrongInputError();
	}
}

vector<vector<int>> getRandomConfiguration(int num) {
	vector<vector<int>> confs;
	for (int i = 0; i < num; i++) {
		confs.push_back(PuzzleUtility::genRandConf(20));
	}

	return confs;
}

int main()
{
	FileManager fm;
	int task = getTask();

	switch (task) {
	case 1:
		insertConfiguration();
		break;

	case 2:
		int numConf;
		cout << "\nHow many configuration do you want to insert?\n";
		cin >> numConf;
		fm.printConfs(getRandomConfiguration(numConf));
		break;

	case 3:
		break;

	default:
		break;
	}

	return 0;
}
