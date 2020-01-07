//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__MYTESTCLIENTHANDLER_H_
#define MILE_STONE2__MYTESTCLIENTHANDLER_H_
#include "Solver.h"
#include "Server.h"
#include "CacheManager.h"
using namespace server_side;
class MyTestClientHandler: public ClientHandler {
  Solver solver_;
  CacheManager cm;
  virtual void handleClient(ifstream& in, ofstream& out);

};

#endif //MILE_STONE2__MYTESTCLIENTHANDLER_H_
