#include <iostream>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"

int main() {
  MySerialServer* s = new MySerialServer();
  ClientHandler *c  = new MyTestClientHandler();
  s->open(12345, c);
  return 0;
}
