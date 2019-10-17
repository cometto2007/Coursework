#include <iostream>
#include "Configuration.h"
#include "Graph.h"

int boardSize = 3;
int i = 0;

int makePermutations(Graph* graph, Configuration conf)
{
	if (!conf.isFinal()) {
		int* moves = conf.getAvailableMoves();
		int count = 0;
		int voidTile = conf.getVoidTile();
		for (int i = 0; i < 4; i++)
		{
			if (moves[i] != -1) {
				Arch* a = graph->getArch(moves[i], voidTile, conf.getTable()[moves[i]]);
				if (a != nullptr && graph->confExist(conf.getTable(), *a)) {

				}
				else {
					graph->addConf(moves[i], voidTile, conf.getTable()[moves[i]], conf.getTable());
					conf.swapTiles(voidTile, moves[i]);
					count = makePermutations(graph, conf);
				}
			}
			
		}
		return count;
	}
	//conf.print();
	cout << "is final " << i <<" \n";
	i++;
	return 1;
}

int test(Configuration conf)
{
	int* moves = conf.getAvailableMoves();
	int count = 0;
	int voidTile = conf.getVoidTile();
	vector<Arch> arches;
	Graph* graph = new Graph(arches, boardSize * boardSize);
	for (int i = 0; i < 4; i++)
	{
		if (moves[i] != -1) {
			graph->addConf(moves[i], voidTile, conf.getTable()[moves[i]], conf.getTable());
			conf.swapTiles(voidTile, moves[i]);
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