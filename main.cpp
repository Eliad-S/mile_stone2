#include <iostream>
#include "MyTestClientHandler.h"
#include "MySerialServer.h"
#include "StringReverser.h"

int main() {
  MySerialServer* s = new MySerialServer();
  CacheManager<string, string>* fileCache= new FileCacheManager<string, string>();
  Solver<string,string>* solver = new StringReverser();
  ClientHandler *c  = new MyTestClientHandler(solver,fileCache);
  s->open(12345, c);


  delete fileCache;
  delete(solver);
  delete(c);
  return 0;
}
