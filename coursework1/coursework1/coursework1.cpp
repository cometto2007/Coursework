#include <iostream>
#include <stack>
#include "Configuration.h"
#include "Graph.h"

using namespace std;

int boardSize = 3;
int i = 0;

struct Move {
	int coord;
	int voidTile;
	vector<int> conf;
};

bool confExist(vector<int> conf, vector<vector<int>>& confs) {
	for (vector<int> c : confs) {
		if (c == conf) {
			return true;
		}
	}
	return false;
}

bool removeConf(vector<int> conf, vector<vector<int>>& confs) {
	for (rsize_t i = 0; i < confs.size(); i++) {
		if (confs[i] == conf) {
			confs.erase(confs.begin() + i);
		}
	}
	return false;
}

void test(Configuration& conf) {
	stack<Move> remMoves;
	vector<vector<int>> confs;
	Configuration* c;

	int voidTile = conf.getVoidTile();
	int* moves = conf.getAvailableMoves();

	for (int i = 0; i < 4; i++) {
		if (moves[i] != -1) {
			Move m = { moves[i], voidTile, conf.getTable() };
			remMoves.push(m);
		}
	}

	while (!remMoves.empty()) {
		Move m = remMoves.top();
		remMoves.pop();

		c = new Configuration(m.conf, boardSize);
		c->swapTiles(m.voidTile, m.coord);

		if (c->isFinal()) {
			// Make something to count the data

			c->print();
			cout << "\n" << i << " final\n\n";
			i++;
		}
		else if (confExist(c->getTable(), confs)) {
			removeConf(c->getTable(), confs);
		} else {
			confs.push_back(c->getTable());
			int* moves = c->getAvailableMoves();
			int voidTile = c->getVoidTile();

			for (int i = 0; i < 4; i++) {
				if (moves[i] != -1) {
					Move m = { moves[i], voidTile, c->getTable() };
					remMoves.push(m);
				}
			}
		}
		delete c;
	}
}

int main()
{
	Configuration* conf = new Configuration(boardSize);
	test(*conf);
}