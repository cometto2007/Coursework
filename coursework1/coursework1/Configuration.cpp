#include "Configuration.h"

Configuration::Configuration(vector<vector<int>> nums, int size)
{
	table = nums;
}

Configuration::Configuration(vector<int> nums)
{
	unsigned int rowSize = (int)sqrt(nums.size());
	for (rsize_t i = 0; i < rowSize; i++) {
		table.push_back(vector<int>(0));
		for (rsize_t j = 0; j < rowSize; j++) {
			table[i].push_back(nums[rowSize * i + j]);
		}
	}
}

Configuration::Configuration(int size) {
	int num = 1;
	for (int i = 0; i < size; i++) {
		table.push_back(vector<int>(0));
		for (int j = 0; j < size; j++) {
			if (i == size - 1 && j == size - 1) {
				table[i].push_back(0);
			} else {
				table[i].push_back(num);
				num++;
			}
		}
	}
}

Configuration::Configuration(const Configuration& src) : table(src.table) 
{
}

Configuration::~Configuration()
{
	for (vector<int> v : table) {
		v.clear();
	}
	table.clear();
}

vector<vector<int>> Configuration::Table() const
{
	return table;
}

vector<int> Configuration::getTableAsVector() const {
	vector<int> res;
	for (vector<int> v : table) {
		for (int n : v) {
			res.push_back(n);
		}
	}
	return res;
}

void Configuration::setTable(vector<vector<int>> newTable)
{
	table = newTable;
}

bool Configuration::isFinal()
{
	return table[table.size() - 1].back() == 0;
}

void Configuration::swapTiles(Coord c1, Coord c2)
{
	int temp = table[c1.x][c1.y];
	table[c1.x][c1.y] = table[c2.x][c2.y];
	table[c2.x][c2.y] = temp;
}

string Configuration::toString()
{
	string out = "";
	for (vector<int> v : table) { 
		for (int n : v) {
			if (n == 0) {
				out += "\t";
			} else {
				out += to_string(n) += "\t";
			}
		}
		out += "\n";
	}
	return out;
}

int Configuration::getRow(int partial, bool voidTile) const
{
	int count = 0;
	for (vector<int> v : table) {
		for (rsize_t i = 0; i + partial - 1 < v.size(); i++) {
			if (isContinuous(vector<int>(v.begin() + i, v.begin() + i + partial), voidTile)) {
				count++;
			}
		}
	}
	return count;
}

bool Configuration::isContinuous(vector<int> v, bool voidTile) const
{
	int prec = v[0];
	for (rsize_t i = 0; i < v.size(); i++) {
		if (v[i] == 0 && i == v.size() - 1 && voidTile) {
			return true;
		}
		if (v[i] != prec + 1 && v[i] != prec) {
			return false;
		}
		prec = v[i];
	}
	return true;
}

bool Configuration::isReverseContinuous(vector<int> v, bool voidTile) const
{
	int prec = v[0];
	for (rsize_t i = 0; i < v.size(); i++) {
		if (v[i] == 0 && i == v.size() - 1 && voidTile) {
			return true;
		}
		if (v[i] != prec - 1 && v[i] != prec) {
			return false;
		}
		prec = v[i];
	}
	return true;
}

int Configuration::getColumn(int partial, bool voidTile) const
{
	vector<int> v;
	int count = 0;
	for (rsize_t i = 0; i < table.size(); i++) {
		for (rsize_t j = 0; j < table.size(); j++) {
			v.push_back(table[j][i]);
		}
		for (rsize_t i = 0; i + partial - 1 < v.size(); i++) {
			if (isContinuous(vector<int>(v.begin() + i, v.begin() + i + partial), voidTile)) {
				count++;
			}
		}
		v.clear();
	}
	return count;
}

int Configuration::getReverseRow(int partial, bool voidTile) const
{
	int count = 0;
	for (vector<int> v : table) {
		for (rsize_t i = 0; i + partial - 1 < v.size(); i++) {
			if (isReverseContinuous(vector<int>(v.begin() + i, v.begin() + i + partial), voidTile)) {
				count++;
			}
		}
	}
	return count;
}

int Configuration::getReverseColumn(int partial, bool voidTile) const
{
	vector<int> v;
	int count = 0;
	for (rsize_t i = 0; i < table.size(); i++) {
		for (rsize_t j = 0; j < table.size(); j++) {
			v.push_back(table[j][i]);
		}
		for (rsize_t i = 0; i + partial - 1 < v.size(); i++) {
			if (isReverseContinuous(vector<int>(v.begin() + i, v.begin() + i + partial), voidTile)) {
				count++;
			}
		}
		v.clear();
	}
	return count;
}

int Configuration::getContinuousOccurrence(int partial) const
{
	vector<int> v = getTableAsVector();
	sort(v.begin(), v.end());
	int count = 0;

	for (rsize_t i = 1;  i + partial - 1 < v.size(); i++) {
		if (isContinuous(vector<int>(v.begin() + i, v.begin() + i + partial))) {
			count++;
		}
	}
	return count;
}

bool Configuration::isValid() const
{
	set<int> set;
	for (vector<int> v : table) {
		for (int n : v) {
			set.insert(n);
		}
	}
	if (set.size() != table.size() * table.size()) {
		return false;
	}
	return true;
}

vector<vector<int>> Configuration::convertVectorToTable(vector<int> nums) {
	vector<vector<int>> conf;
	for (rsize_t i = 0; i < nums.size(); i++) {
		conf.push_back(vector<int>(0));
		for (rsize_t j = 0; j < nums.size(); j++) {
			conf[i].push_back(nums[i + j]);
		}
	}
	return conf;
}
