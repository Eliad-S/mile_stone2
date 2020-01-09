//
// Created by eliadsellem on 1/6/20.
//
#include <fstream>
#ifndef MILE_STONE2__CLIENTHANDLER_H_
#define MILE_STONE2__CLIENTHANDLER_H_
using namespace std;
class ClientHandler{
 public:
  virtual void handleClient(int socket) = 0;
  virtual ~ClientHandler(){}
};
#endif //MILE_STONE2__CLIENTHANDLER_H_
