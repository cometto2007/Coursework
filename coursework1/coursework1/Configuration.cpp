#include "Configuration.h"

Configuration::Configuration(vector<int> nums, int size):
	rowSize(size), totalSize(size * size)
{
	table = vector<int>(totalSize);
	for (int i = 0; i < totalSize; i++)
	{
			table[i] = nums[i];
	}
}

Configuration::Configuration(int size):
	rowSize(size), totalSize(size * size)
{
	int num = 1;
	table = vector<int>(0);
	for (int i = 0; i < totalSize - 1; i++)
	{
		table.push_back(num);
		num++;
	}
	table.push_back(-1);
}

Configuration::Configuration(const Configuration& src) :
	rowSize(src.rowSize), totalSize(src.totalSize)
{
	table = vector<int>(src.totalSize);
	for (int i = 0; i < src.totalSize; i++)
	{
		table[i] = src.table[i];
	}
}

Configuration::~Configuration()
{
	table.clear();
}

vector<int> Configuration::getTable() const
{
	return table;
}

void Configuration::setTable(vector<int> nums)
{
	for (int i = 0; i < totalSize; i++)
	{
			table[i] = nums[i];
	}
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

	if (voidTile >= totalSize - rowSize) down = -1;
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

void Configuration::print()
{
	for (int i = 0; i < totalSize; i++) {
		cout << table[i] << "\t";
		if ((i + 1) >= rowSize && (i + 1) % rowSize == 0) {
			cout << "\n\n";
		}
	}
	cout << "\n\n\n";
}
