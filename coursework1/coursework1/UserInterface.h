#pragma once
#include <iostream>

using namespace std;

class UserInterface
{
public:
	static void printMainMenu();
	static void printInsertConfigurationSection();
	static void printCreateRandomConfigurationSection();
	static void printWrongInputError();
};

