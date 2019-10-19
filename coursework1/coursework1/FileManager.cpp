#include "FileManager.h"

FileManager::FileManager()
{
	outfile.open("puzzles.txt");
}

void FileManager::printConfs(vector<vector<int>> confs)
{
	outfile << confs.size() << "\n";
	for (vector<int> conf : confs) {
		for (int i = 0; i < conf.size(); i++) {
			outfile << conf[i] << "\t";
			if ((i + 1) >= int(sqrt(conf.size())) && ((i + 1) % int(sqrt(conf.size())) == 0)) {
				outfile << "\n\n";
			}
		}
		outfile << "\n\n";
	}
}
