//
// Created by eliadsellem on 1/6/20.
//
#include "MyTestClientHandler.h"
void MyTestClientHandler:: handleClient(ifstream& in, ofstream& out){

  out<<"hello its a massage from the input file\n";
  in.seekg(0, in.end);
  int length = in.tellg();
  in.seekg(0, in.beg);

  char *buffer = new char[length];
  in.read(buffer, length);

  out<<buffer;

}
