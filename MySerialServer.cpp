//
// Created by eliadsellem on 1/6/20.
//

#include <netinet/in.h>
#include "MySerialServer.h"


void  MySerialServer:: open(int p, ClientHandler c) {
  char buffer[1500] = {0};
  ofstream in ("massage.txt", ios::out);
  ofstream out ("solution.txt", ios::out);
  int port = p;
  int SOCK_STREAM;
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
  if (listen(sockfd, 1) == -1) {
    cerr << "error during listening command" << endl;
  }
  while(true) {
    //accepting a client.
    int server_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    read(server_socket, buffer, 1500);
    writeIntoFile(in, buffer);
    if (server_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }
  }
}
void MySerialServer::writeIntoFile(ofstream& out, char *buffer, int size) {


}
