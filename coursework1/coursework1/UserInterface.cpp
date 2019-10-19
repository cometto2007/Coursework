#include "UserInterface.h"

void UserInterface::printMainMenu()
{
	cout << "\n\n15 Puzzle Program\n\n";
	cout << "1. Insert a configuration\n";
	cout << "2. Create Random Configuration\n";
	cout << "3. Get results from the solutions file\n\n";
	cout << "Insert your choice\n\n";
}

void UserInterface::printInsertConfigurationSection()
{
	cout << "\nInsert numbers from 1 to 20 (inclusive) without repetition separated by a space\n\n";
}

void UserInterface::printCreateRandomConfigurationSection()
{
	cout << "\nThe generated configuration is: \n";
	cout << "\nThe generated configuration is: \n";
}

void UserInterface::printWrongInputError()
{
	cout << "\nYou put an invalid input, retry\n";
}
