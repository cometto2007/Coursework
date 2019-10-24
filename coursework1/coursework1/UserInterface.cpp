#include "UserInterface.h"

int UserInterface::getMainTask(int puzzleSize)
{
	int choice = 0;
	cout << "\n\n" << puzzleSize << " Puzzle Program\n\n";
	cout << "1. Insert a configuration\n";
	cout << "2. Create Random Configuration\n";
	cout << "3. Get results from the solutions file\n\n";
	cout << "Insert your choice\n";
	
	cin >> choice;

	while (choice < 1 || choice > 3) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\nYou put an invalid input, you have to put a number between 1 to 3, retry\n";
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

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	bool retry = true;
	int numConf;
	cout << "\nHow many configuration do you want to insert?\n";
	cin >> numConf;

	while (retry) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nYou put an invalid input, you have to put a number, retry\n";
			cin >> numConf;
		} else {
			retry = false;
		}
	}

	vector<vector<int>> confs = PuzzleUtility::genRandConfs(numConf, puzzleSize);
	printOnScreen(PuzzleUtility::printConfs(confs));

	return confs;
}

int UserInterface::getResultMenuTask() {
	int choice;
	cout << "\n1. Do you want to find a custom partial continuous row and continuous column (including reverse) in any puzzle configuration of the file?\n";
	cout << "2. Do you want to find a custom partial continuous row and continuous column (including reverse) in all reacheable configuration in any puzzle configuration of the file?\n";
	cout << "3. Do you want to find all The possible data in all reacheable configuration in any puzzle configuration of the file?\n";
	cout << "\nInsert your choice\n";

	cin >> choice;
	while (choice < 1 || choice > 3) {
		cout << "\nYou put an invalid input, you have to put a number between 1 to 3, retry\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cin >> choice;
	}

	return choice;
}

int UserInterface::getPartialNum() {
	int choice = 0;
	cout << "\nInsert a number to indicate the n-partial row/column you want to find\n";

	cin >> choice;
	while (choice <= 1) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nYou put an invalid input, you have to put a number, retry\n";
		} else {
			cout << "\nYou put an invalid input, you have to put a number > 1, retry\n";
		}
		cin >> choice;
	}
	return choice;
}

bool UserInterface::getIncludeVoid() {
	cout << "\nDo you want include the row with the void tile in the calculations? (y/n)\n";
	return checkForYNInput();
}

void UserInterface::printOnScreen(string res) {
	cout << "\nDo you want to print results on screen? (y/n)\n";
	if (checkForYNInput()) {
		cout << res;
	}
}

void UserInterface::printOnFile(FileManager* fm, string res) throw (invalid_argument) {
	bool error = true;
	cout << "\nDo you want to print results on file? (y/n)\n";

	if (checkForYNInput()) {
		string fileName;
		cout << "\nInsert the name of the file without extension\n";

		while (error) {
			cin >> fileName;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (isValidFileName(fileName)) {
				try {
					fm->printResults(res, fileName + ".txt", ofstream::out);
					error = false;
				} catch (const invalid_argument & iae) {
					cout << "\nunable print data: " << iae.what() << ", retry\n";
				}
			} else {
				cout << "\nYou put an invalid filename, retry\n";
			}
		}
	}
}

vector<vector<int>> UserInterface::getConfsFromFile(FileManager* fm, int puzzleSize) throw (invalid_argument) {
	vector<vector<int>> res;
	bool error = true;
	string fileName;
	cout << "\nInsert the name of the file without extension\n";
	
	while (error) {
		cin >> fileName;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		if (isValidFileName(fileName)) {
			try {
				res = fm->getConfs(puzzleSize, fileName + ".txt");
				if (!validateConf(res)) {
					cout << "\nFile has invalid Configuration, please insert another one\n";
				} else {
					error = false;
				}
			} catch (const invalid_argument & iae) {
				cout << "\nunable read data: " << iae.what() << ", retry\n";
			}
		} else {
			cout << "\nYou put an invalid filename, retry\n";
		}
	}
	return res;
}

bool UserInterface::runProgAgain() {
	cout << "\nDo you want to run the program again? (y/n)\n";
	return checkForYNInput();
}

int UserInterface::choosePuzzleSize() {
	bool check = false;
	int puzzleSize;
	cout << "\nWhat is the size of the puzzles you want to use? (15-Puzzle, 24-Puzzle, 35-Puzzle, ecc.)\n";
	do {
		cin >> puzzleSize;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nYou put an invalid input, you have to put a number, retry\n";
		} else {
			check = puzzleSize >= 8 && sqrt(puzzleSize + 1) - (int)sqrt(puzzleSize + 1) == 0;
			if (!check) {
				cout << "\nYou put an invalid input, must be a squared number - 1, retry\n";
			}
		}
	} while (!check);
	return puzzleSize;
}

bool UserInterface::checkForYNInput() {
	char choice;
	cin >> choice;
	while (choice != 'y' && choice != 'n') {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "\nYou put an invalid input, you have to put 'y' or 'n', retry\n";
		cin >> choice;
	}
	return choice == 'y';
}

bool UserInterface::isValidFileName(string fileName) {
	bool foundInvalidChar = fileName.find('<') != string::npos ||
		fileName.find('>') != string::npos ||
		fileName.find('\\') != string::npos ||
		fileName.find('/') != string::npos ||
		fileName.find(':') != string::npos ||
		fileName.find('*') != string::npos ||
		fileName.find('?') != string::npos ||
		fileName.find('|') != string::npos ||
		fileName.find('"') != string::npos;
	return !foundInvalidChar;
}

bool UserInterface::validateConf(vector<vector<int>>& confs) {
	for (vector<int> c : confs) {
		Configuration conf(c);
		if (!conf.isValid()) {
			return false;
		}
	}
	return true;
}
