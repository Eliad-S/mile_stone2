#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "Point.h"
#include "ISearchable.h"
#include "SolverSearch.h"
#include "BestFirstSearch.h"
#include "MyClientHandler.h"
#include "AStar.h"
#include "DFS.h"
#include "BFS.h"
#include "MyParallelServer.h"
#include "RunMatrix.h"
#include "Boot.h"
using namespace Boot;
vector<double> runAlgorithm(ISearchable<Point *> *matrix, Searcher<Point *, string> *search) {
    vector<double> result;
    for (int i = 0; i < 10; i++) {
        search->search(matrix);
        result.push_back(search->getNumberOfNodesEvaluated());
    }
    return result;
}

vector<vector<double >> runAllAlgorithm(ISearchable<Point *> *matrix, vector<Searcher<Point *, string> *> searcher) {
    vector<vector<double >> result;
    for (auto s: searcher) {
        result.push_back(runAlgorithm(matrix, s));
    }
    return result;
}

string readFromFile(string file) {
    string content = "";
    ifstream inFile(file);
    if (!inFile) {
        throw "Can't open file";
    }
    string line;
    while (std::getline(inFile, line)) {
        content += line + '\n';
    }
    inFile.close();
    return content;
}

int main(int argc, char* argv[]) {



    Main* m = new Main();
    if (argc < 2) {
        m->main(5600);
    } else {
        m->main(atoi(argv[1]));
    }
    return 0;
}
