//
// Created by shirgold on 13/01/2020.
//

#include <vector>
#include <netinet/in.h>
#include "MyParallelServer.h"
#include "CacheManager.h"
#include "Solver.h"
#include "ISearchable.h"
#include "MySerialServer.h"

void MyParallelServer::open(int p, ClientHandler *c) {
  int client_socket, iResult;
  int port = p;
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    //error
    cerr << "could'nt open the socket" << endl;
  }
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    cerr << "could'nt bind the socket to an ip" << endl;
  }
//making socket listen to the port
  if (listen(sockfd, 10) == -1) {
    cerr << "error during listening command" << endl;
  }
  for(int i=0; i<10; i++){
    //clone c
    MySerialServer* s= new MySerialServer();
    ClientHandler* client_handler = c->clone();
    serialServer.push_back(s);
    threads.push_back(thread(&MySerialServer::start,s, sockfd, address, client_handler));
  }
  for (int i = 9; i >= 0; i++) {
    threads[i].join();
    threads.pop_back();
  }
  close(client_socket);
}
void MyParallelServer::start(int client_socket, sockaddr_in address, ClientHandler *c) {

  string bufferOut;
  c->handleClient(client_socket);
  //while the client still sending massage - to "End"
}

void MyParallelServer::stop() {
  for(MySerialServer* s:serialServer){
    s->shouldStop = true;
  }
}



