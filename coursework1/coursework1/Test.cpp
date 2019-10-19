#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
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

bool confExist(float conf, vector<float>& confs) {
	for (float c : confs) {
		if (c == conf) {
			return true;
		}
	}
	return false;
}

bool removeConf(float conf, vector<float>& confs) {
	for (rsize_t i = 0; i < confs.size(); i++) {
		if (confs[i] == conf) {
			confs.erase(confs.begin() + i);
		}
	}
	return false;
}

float getWholeNumber(vector<int> conf) {

	string s = "";
	for (rsize_t i = 0; i < conf.size(); i++) {
		if (conf[i] == -1) {
			s += to_string(0);
		}
		else {
			s += to_string(conf[i]);
		}
	}

	return stof(s);
}

void areThereDuplicates(vector<int> v) {
	int dupl = 0;
	sort(v.begin(), v.end());
	for (rsize_t i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) {
			dupl++;
			i--;
		}
	}
	cout << "duplicates are: " << dupl << "\n\n";
}

void testWithBreadthFirstSearchNoDuplWholeTree(Configuration& conf) {
	queue<Move> remMoves;
	vector<float> confs;
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
		Move m = remMoves.front();
		remMoves.pop();

		c = new Configuration(m.conf, boardSize);
		c->swapTiles(m.voidTile, m.coord);

		if (c->isFinal()) {
			// Make something to count the data

			//c->print();
			cout << "\n" << i << " final\n\n";
			i++;
		}
		else {
			if (!confExist(getWholeNumber(c->getTable()), confs)) {
				confs.push_back(getWholeNumber(c->getTable()));
				int* moves = c->getAvailableMoves();
				int voidTile = c->getVoidTile();

				for (int i = 0; i < 4; i++) {
					if (moves[i] != -1) {
						Move m = { moves[i], voidTile, c->getTable() };
						remMoves.push(m);
					}
				}
			}
		}
		delete c;
	}
}

void testWithDepthFirstSearchNoDuplWholeTree(Configuration& conf) {
	stack<Move> remMoves;
	vector<float> confs;
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

			//c->print();
			cout << "\n" << i << " final\n\n";
			i++;
		}
		else {
			if (!confExist(getWholeNumber(c->getTable()), confs)) {
				confs.push_back(getWholeNumber(c->getTable()));
				int* moves = c->getAvailableMoves();
				int voidTile = c->getVoidTile();

				for (int i = 0; i < 4; i++) {
					if (moves[i] != -1) {
						Move m = { moves[i], voidTile, c->getTable() };
						remMoves.push(m);
					}
				}
			}
		}
		delete c;
	}
}

bool confrontTable(vector<int> v1, vector<int> v2) {
	for (rsize_t i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i]) {
			return false;
		}
	}
	return true;
}

void test(Configuration& conf) {
	stack<Move> remMoves;
	vector<float> confs;
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

			//c->print();
			//cout << "\n" << i << " final\n\n";
			//i++;
			vector<int> v2;
			v2.push_back(8);
			v2.push_back(3);
			v2.push_back(4);
			v2.push_back(2);
			v2.push_back(1);
			v2.push_back(5);
			v2.push_back(6);
			v2.push_back(7);
			v2.push_back(-1);

			if (confrontTable(c->getTable(), v2)) {
				cout << "\nThe configuration exist\n\n";
				return;
			}

		}
		else if (confExist(getWholeNumber(c->getTable()), confs)) {
			removeConf(getWholeNumber(c->getTable()), confs);
		}
		else {
			confs.push_back(getWholeNumber(c->getTable()));
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