//
// Created by shirgold on 13/01/2020.
//

#ifndef MILE_STONE2_MYPARALLELSERVER_H
#define MILE_STONE2_MYPARALLELSERVER_H
#include "Server.h"
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
using namespace server_side;
class MyParallelServer : public Server {
 public:
  virtual void open(int p, ClientHandler *c);
  static void start(int client_socket, sockaddr_in address, ClientHandler *c);
  virtual void stop();
  bool shouldStop;
};

#endif //MILE_STONE2_MYPARALLELSERVER_H
