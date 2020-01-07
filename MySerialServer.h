//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__MYSERIALSERVER_H_
#define MILE_STONE2__MYSERIALSERVER_H_
#include "Server.h"
#include <iostream>
#include <fstream>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;
using namespace server_side;
class MySerialServer: public Server {
 public:
  virtual void open(int p, ClientHandler* c);
  virtual void stop();
//  void writeIntoFile(string fileName, char * buffer ,int size);
  char* readFromFile();
};

#endif //MILE_STONE2__MYSERIALSERVER_H_
