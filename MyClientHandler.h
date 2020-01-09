//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__MYCLIENTHANDLER_H_
#define MILE_STONE2__MYCLIENTHANDLER_H_

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "ISearchable.h"
#include "Point.h"
using namespace std;
class MyClientHandler : public ClientHandler{
  string allProblem = "";
  Solver<ISearchable<Point>*,string> *solver;
  CacheManager<string, string> *file_cache;
  virtual void handleClient(int socket) = 0;
  ISearchable<Point>* createMatrix(string s);
};

#endif //MILE_STONE2__MYCLIENTHANDLER_H_
