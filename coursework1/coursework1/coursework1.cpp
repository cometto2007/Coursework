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

vector<vector<int>> UserConfiguration() {
	string numbers = "";
	vector<vector<int>> confs(0);
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
		} else {
			vector<int> conf(set.begin(), set.end());
			conf.push_back(0);
			confs.push_back(conf);
		}
	} else {
		UserInterface::printWrongInputError();
	}
	return confs;
}

int main()
{
	FileManager fm("15-File.txt", "Solution-File.txt");
	vector<vector<int>> confs(0);
	bool execute = true;

	while (execute) {
		int task = getTask();

		switch (task) {
		case 1:
			fm.printConfs(UserConfiguration(), ofstream::out);
			break;

		case 2:
			int numConf;
			cout << "\nHow many configuration do you want to insert?\n";
			cin >> numConf;
			fm.printConfs(PuzzleUtility::genRandConfs(numConf, 20), ofstream::out);
			break;

		case 3:
			 confs = fm.getConfs(16);
			 fm.printResults(confs, ofstream::out);
			break;

		default:
			break;
		}
		cout << "\nDo you want to run the program again? (y/n)\n";
		char answer;
		cin >> answer;
		answer == 'y' ? execute = true : execute = false;
	}
	
	return 0;
}
