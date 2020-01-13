#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "StringReverser.h"
#include "Point.h"
#include "ISearchable.h"
#include "SolverSearch.h"
#include "BestFirstSearch.h"
#include "MyClientHandler.h"
#include "BFS.h"
int main() {
  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* fileCache= new FileCacheManager<string, string>();
  Solver<string,string>* solver = new StringReverser();
  Searcher<Point*,string> * bfs = new BFS<Point*,string>();
  Solver<ISearchable<Point*>*,string> *solverS = new SolverSearch<ISearchable<Point*>*,string,Point*>(bfs);
  ClientHandler *c  = new MyClientHandler(solverS,fileCache);
  s->open(12346, c);


  delete fileCache;
  delete(solver);
  delete(c);
  return 0;
}
