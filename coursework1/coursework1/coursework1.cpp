#include <iostream>
#include "Configuration.h"
#include "Graph.h"

int boardSize = 3;
int i = 0;

int makePermutations(Graph* graph, Configuration conf)
{
	conf.print();
	if (!conf.isFinal()) {
		int* moves = conf.getAvailableMoves();
		int count = 0;
		int voidTile = conf.getVoidTile();
		for (int i = 0; i < 4; i++)
		{
			if (moves[i] != -1 && !graph->edgeExist(moves[i], voidTile, conf.getTable()[moves[i]])) {
				Edge e = { moves[i], voidTile,  conf.getTable()[moves[i]] };
				conf.swapTiles(voidTile, moves[i]);
				graph->addEdge(e);
				count = makePermutations(graph, conf);
			}
		}
		return count;
	}
	cout << "is final " << i <<" \n";
	i++;
	return 1;
}

int test(Configuration conf)
{
	int* moves = conf.getAvailableMoves();
	int count = 0;
	int voidTile = conf.getVoidTile();
	vector<Edge> edges;
	Graph* graph = new Graph(edges, boardSize * boardSize);
	for (int i = 0; i < 4; i++)
	{
		if (moves[i] != -1) {
			Edge e = { moves[i], voidTile,  conf.getTable()[moves[i]] };
			conf.swapTiles(voidTile, moves[i]);
			graph->addEdge(e);
			count += makePermutations(graph, conf);
		}

	}
	return count;
}

int main()
{
	Configuration* conf = new Configuration(boardSize);
	std::cout << test(*conf);
}