//
// Created by shirgold on 13/01/2020.
//

#include <vector>
#include <netinet/in.h>
#include "MyParallelServer.h"
#include "CacheManager.h"
#include "Solver.h"
#include "ISearchable.h"

void MyParallelServer::open(int p, ClientHandler *c) {
  int client_socket, iResult;
  int port = p;
  vector<thread> threads;
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
  int noThread = 0;

  while (noThread < 10 && !MyParallelServer::shouldStop) {
    cout << "Listening" << endl;
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv;
    tv.tv_sec = (long) 10;
    tv.tv_usec = 0;
    iResult = select(sockfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {
      client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    } else {
      cout << "didnt connect" << endl;
      continue;
    }
    if (client_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }

    threads.push_back(thread(start, sockfd, address, c));
    noThread++;
  }

  for (int i = noThread-1; i >= 0; i++) {
    threads[i].join();
    threads.pop_back();
  }

}
void MyParallelServer::start(int client_socket, sockaddr_in address, ClientHandler *c) {

  string bufferOut;
  c->handleClient(client_socket);
  //while the client still sending massage - to "End"
  close(client_socket);
}

void MyParallelServer::stop() {
  MyParallelServer::shouldStop = true;
}



