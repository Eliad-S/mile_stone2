//
// Created by eliadsellem on 1/6/20.
//


#include "MySerialServer.h"
#define INPUT_FILE "massage.txt"
#define OUT_FILE "solution.txt"
bool MySerialServer::shouldStop = false;
void MySerialServer::open(int p, ClientHandler *c) {

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
  if (listen(sockfd, 1) == -1) {
    cerr << "error during listening command" << endl;
  }
  MySerialServer::start(sockfd, address, c);
  //thread listen_thread (start ,sockfd, address ,c);
  //shouldStop = true;
  //listen_thread.join();


}
void MySerialServer::start(int sockfd, sockaddr_in address, ClientHandler *c) {

  int iResult, server_socket, valRead;
  char bufferIn[1500] = {0};
  string bufferOut;
  while (!MySerialServer::shouldStop) {
    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sockfd, &rfds);
    struct timeval tv;
    tv.tv_sec = (long) 10;
    tv.tv_usec = 0;
    iResult = select(sockfd + 1, &rfds, (fd_set *) 0, (fd_set *) 0, &tv);
    if (iResult > 0) {
      server_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    } else {
      cout << "didnt connect" << endl;
      continue;
    }
    if (server_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }
    c->handleClient(server_socket);
    //while the client still sending massage - to "End"
    close(server_socket);
    //break;
  }
  close(sockfd);
}

void MySerialServer::stop() {
  MySerialServer::shouldStop = true;
}

string MySerialServer::readFromFile() {
  ifstream out(OUT_FILE, ios::in);
  if (!out) {
    cerr << "can't open file" << endl;
    exit(1);
  }

  // get length of file:
  out.seekg(0, out.end);
  int length = out.tellg();
  out.seekg(0, out.beg);

  char *buffer = new char[length];

  std::cout << "Reading " << length << " characters... \n";
  // read data as a block:
  out.read(buffer, length);

  if (out)
    std::cout << "all characters read successfully.\n";
  else
    std::cout << "error: only " << out.gcount() << " could be read\n";
  out.close();
  string solution = string(buffer);
  return solution.substr(0, length);
}

