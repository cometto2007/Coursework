#include "UserInterface.h"

int UserInterface::getMainTask(int puzzleSize)
{
	int choice = 0;
	cout << "\n\n" << puzzleSize << " Puzzle Program\n\n";
	cout << "1. Insert a configuration\n";
	cout << "2. Create Random Configuration\n";
	cout << "3. Get results from the solutions file\n\n";
	cout << "Insert your choice\n\n";
	
	cin >> choice;

	while (choice < 1 || choice > 3) {
		cout << "\nYou put an invalid input, you have to put a number between 1 to 3\n";
		cin >> choice;
	}

	return choice;
}

vector<int> UserInterface::getUserConfiguration(int puzzleSize)
{
	string numbers = "";
	vector<int> conf;
	bool retry = true;
	while (retry == true) {
		cout << "\nInsert " << puzzleSize << " numbers from 1 to " << puzzleSize + 5 << "(inclusive) without repetition separated by a space\n\n";

		cin.ignore();
		cin.clear();
		getline(cin, numbers);

		if (PuzzleUtility::isComposedByNumber(numbers)) {
			stringstream ss(numbers);

			set<int> set;

			for (int i = 0; ss >> i; ) {
				if (i && i > 0 && i <= puzzleSize + 5) {
					set.insert(i);
				}
			}
			if (set.size() != puzzleSize) {
				cout << "\nYou put an invalid input, too many item, retry\n";
			} else {
				conf = vector<int>(set.begin(), set.end());
				retry = false;
			}
		} else {
			cout << "\nYou put invalid character, retry\n";
		}
	}
	printOnScreen(PuzzleUtility::printConf(conf));
	return conf;
}

vector<vector<int>> UserInterface::generateRandomConfs(int puzzleSize) {
	int numConf;
	cout << "\nHow many configuration do you want to insert?\n";
	cin >> numConf;

	vector<vector<int>> confs = PuzzleUtility::genRandConfs(numConf, puzzleSize);
	printOnScreen(PuzzleUtility::printConfs(confs));

	return confs;
}

int UserInterface::getResultMenuTask() {
	int choice;
	cout << "\n1. Do you want to find a custom partial continuous row and continuous column (including reverse) in any puzzle configuration of the file?\n";
	cout << "2. Do you want to find a custom partial continuous row and continuous column (including reverse) in all reacheable configuration in any puzzle configuration of the file?\n";
	cout << "3. Do you want to find all The possible data in all reacheable configuration in any puzzle configuration of the file?\n";
	cout << "\nInsert your choice\n\n";

	cin >> choice;
	while (choice < 1 || choice > 3) {
		cout << "\nYou put an invalid input, you have to put a number between 1 to 3\n";
		cin >> choice;
	}

	return choice;
}

int UserInterface::getPartialNum() {
	int choice;
	cout << "\nInsert a number to indicate the n-partial row/column you want to find\n";

	cin >> choice;
	while (choice <= 0) {
		cout << "\nYou put an invalid input, you have to put a number > 0, retry\n";
		cin >> choice;
	}
	return choice;
}

bool UserInterface::getIncludeVoid() {
	char choice;
	cout << "\nDo you want include the row with the void tile in the calculations? (y/n)\n";

	cin >> choice;
	while (choice != 'y' && choice != 'n') {
		cout << "\nYou put an invalid input, you have to put 'y' or 'n', retry\n";
		cin >> choice;
	}
	return choice == 'y';
}

void UserInterface::printOnScreen(string res) {
	cout << "\nDo you want to print results on screen? (y/n)\n";
	char answer;
	cin >> answer;
	if (answer == 'y') {
		cout << res;
	}
}

void UserInterface::printOnFile(FileManager* fm, string res) {
	bool error = true;
	cout << "\nDo you want to print results on file? (y/n)\n";
	char answer;
	cin >> answer;
	if (answer == 'y') {
		string fileName;
		cout << "Insert the name of the file\n";
		cin >> fileName;

		while (error) {
			try {
				fm->printResults(res, fileName, ofstream::out);
				error = false;
			} catch (const invalid_argument & iae) {
				cout << " unable print data: " << iae.what() << ", retry\n";
			}
		}
	}
}

vector<vector<int>> UserInterface::getConfsFromFile(FileManager* fm, int puzzleSize) {
	vector<vector<int>> res;
	bool error = true;
	string fileName;
	cout << "Insert the name of the file\n";
	cin >> fileName;

	while (error) {
		try {
			res = fm->getConfs(puzzleSize,fileName);
			error = false;
		} catch (const invalid_argument & iae) {
			cout << " unable print data: " << iae.what() << ", retry\n";
		}
	}
	return res;
}

bool UserInterface::runProgAgain() {
	cout << "\nDo you want to run the program again? (y/n)\n";
	char answer;
	cin >> answer;
	return answer == 'y';
}

int UserInterface::choosePuzzleSize() {
	bool check = true;
	int puzzleSize;
	do {
		cout << "\nWhat is the size of the puzzles you want to use? (15-Puzzle, 24-Puzzle, 35-Puzzle, ecc.)\n";
		cin >> puzzleSize;
		check = sqrt(puzzleSize + 1) - (int)sqrt(puzzleSize + 1) == 0;
		if (!check) {
			cout << "\nMust be a squared number - 1\n";
		}
	} while (!check);
	return puzzleSize;
}
