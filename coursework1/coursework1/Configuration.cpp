#include "Configuration.h"

Configuration::Configuration(int* nums, int size):
	rowSize(size), totalSize(size * size)
{
	table = new int[totalSize];
	for (int i = 0; i < totalSize; i++)
	{
			table[i] = nums[i];
	}
}

Configuration::Configuration(int size):
	rowSize(size), totalSize(size * size)
{
	int num = 1;
	table = new int[totalSize];
	for (int i = 0; i < totalSize - 1; i++)
	{
		table[i] = num;
		num++;
	}
	table[totalSize - 1] = -1;
}

Configuration::~Configuration()
{
	delete[] table;
}

int* Configuration::getTable() const
{
	return table;
}

void Configuration::setTable(int* nums)
{
	for (int i = 0; i < totalSize; i++)
	{
			table[i] = nums[i];
	}
}

int Configuration::test()
{
	int* moves = getAvailableMoves();
	int count = 0;
	int voidTile = getVoidTile();
	for (int i = 0; i < 4; i++)
	{
		swapTiles(voidTile, moves[i]);
		count = makePermutations();
	}
	return count;
}

bool Configuration::isFinal()
{
	return table[totalSize - 1] == -1;
}

int Configuration::getVoidTile()
{
	for (int i = 0; i < totalSize; i++)
	{
		if (table[i] == -1) {
			return i;
		}
	}
	return -1;
}

int* Configuration::getAvailableMoves()
{
	int voidTile = getVoidTile();
	int left, right, up, down;
	int* moves = new int[4];
	
	if (voidTile < rowSize) up = -1;
	else up = voidTile - rowSize;

	if (voidTile > totalSize - rowSize) down = -1;
	else down = voidTile + rowSize;

	if (voidTile % rowSize == 0) left = -1;
	else left = voidTile - 1;

	if (voidTile % rowSize == rowSize - 1) right = -1;
	else right = voidTile + 1;

	moves[0] = left;
	moves[1] = right;
	moves[2] = up;
	moves[3] = down;

	return moves;
}

void Configuration::swapTiles(int index1, int index2)
{
	int temp = table[index1];
	table[index1] = table[index2];
	table[index2] = temp;
}

int Configuration::makePermutations()
{
	if (!isFinal()) {
		int* moves = getAvailableMoves();
		int count = 0;
		int voidTile = getVoidTile();
		for (int i = 0; i < 4; i++)
		{

			if (moves[i] != -1) {
				swapTiles(voidTile, moves[i]);
				count = makePermutations() + 1;
			}
		}
		return count;
	}
	return 0;
}
