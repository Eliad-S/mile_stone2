//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__MYTESTCLIENTHANDLER_H_
#define MILE_STONE2__MYTESTCLIENTHANDLER_H_
#include "Solver.h"
#include "Server.h"
#include "FileCacheManager.h"
#include <iostream>
using namespace server_side;
class MyTestClientHandler: public ClientHandler {
  Solver<string,string> *solver;
  CacheManager<string, string> *file_cache;
  virtual void handleClient(int client_socket);
 public:
  MyTestClientHandler(Solver<string,string> *solver_,CacheManager<string,string>* cache) {
    this->solver = solver_;
    this->file_cache = cache;
  }
};

#endif //MILE_STONE2__MYTESTCLIENTHANDLER_H_
