//
// Created by eliadsellem on 1/6/20.
//

#include <netinet/in.h>
#include <cstring>
#include "MySerialServer.h"
#define INPUT_FILE "massage.txt"
#define OUT_FILE "solution.txt"
void MySerialServer::open(int p, ClientHandler* c) {
  int valread;
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

  char bufferIn[1500] = {0};
  char *bufferOut;
  int length = 0;
  bool yes = true;
  while (yes) {
    //accepting a client.
    int server_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);

    if (server_socket == -1) {
      cerr << "Error accepting clinet" << endl;
    }
    //open output steam to write the input massage
    ofstream in(INPUT_FILE, ios::out);
    //receive massage
    valread = read(server_socket, bufferIn, 1500);
    string msg = string(bufferIn);
    msg = msg.substr(0, valread);
    //write the massage into file
    in << bufferIn;
    in.close();
    ifstream input(INPUT_FILE, ios::in);
    ofstream output(OUT_FILE, ios::out);
    c->handleClient(input, output);
    output.close();
    input.close();
    bufferOut = readFromFile();
    int is_send = send(server_socket, bufferOut, strlen(bufferOut), 0);
    if (is_send == -1) {
      cerr<< "error sending massage to client"<<endl;
    }
    cout<<"bufferOut"<<bufferOut<<endl;
    close(server_socket);
  }
}

//void MySerialServer::writeIntoFile(string fileName, char *buffer, int size) {
//  // Write Buffer
//  FILE *ptrF = fopen("massage.txt", "w");
//  if (fwrite(buffer, 1, size, ptrF) != size) {
//    printf("ERROR - Failed to write %i bytes to file\n", size);
//    exit(1);
//  }
//  fclose(ptrF);
//}
void MySerialServer::stop() {}
char *MySerialServer::readFromFile() {
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

  std::cout << "Reading " << length << " characters... ";
  // read data as a block:
  out.read(buffer, length);

  if (out)
    std::cout << "all characters read successfully.";
  else
    std::cout << "error: only " << out.gcount() << " could be read";
  out.close();
  return buffer;
}
