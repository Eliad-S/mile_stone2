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
    MyParallelServer *s = new MyParallelServer();
    CacheManager<string, string> *fileCache = new FileCacheManager();
    Solver<string, string> *solver = new StringReverser();
    RunMatrix* run = new RunMatrix();
    map<string, vector<vector<double >>> map = run->returnResults(fileCache);


    //searcher
    Searcher<Point *, string> *aStar = new AStar<Point *, string>();
    Searcher<Point *, string> *BestFS = new BestFirstSearch<Point *, string>();
    Searcher<Point *, string> *dfs = new DFS<Point *, string>();
    Searcher<Point *, string> *bfs = new BFS<Point *, string>();

    //solvers
    Solver<ISearchable<Point *> *, string> *solverAStar = new SolverSearch<string, Point *>(aStar);
    Solver<ISearchable<Point *> *, string> *solverBestFS = new SolverSearch<string, Point *>(BestFS);
    Solver<ISearchable<Point *> *, string> *solverDFS = new SolverSearch<string, Point *>(dfs);
    Solver<ISearchable<Point *> *, string> *solverBFS = new SolverSearch<string, Point *>(bfs);

    //clients
    ClientHandler *c1 = new MyClientHandler(solverBFS, fileCache);
    ClientHandler *c2 = new MyClientHandler(solverBestFS, fileCache);
    ClientHandler *c3 = new MyClientHandler(solverDFS, fileCache);
    ClientHandler *c4 = new MyClientHandler(solverAStar, fileCache);

    s->open(atoi(argv[1]), c4);

    delete fileCache;
    delete (solver);
    delete (c1);
    return 0;
}
