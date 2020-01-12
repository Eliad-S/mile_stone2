//
// Created by eliadsellem on 1/6/20.
//
#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"
void MyTestClientHandler:: handleClient(int client_socket){
  while(true) {
    char buffer[1500] = {0};
    //receive massage
    int valRead = read(client_socket, buffer, 1500);
    if(valRead == 0) {
      break;
    }
    string problem = string(buffer);
    problem = problem.substr(0, valRead);

    if (problem.compare("End") == 0) {
      cout << "endddd" << endl;
      close(client_socket);
      break;
    }
    //write the massage into file
    cout << "buffer : " << buffer << endl;
    string solution;
    if(file_cache->isSolved(problem)) {
      solution = file_cache->getSolution(problem);
      cout<<"from file: "<<solution<<endl;
    }else {
      solution = solver->solve(problem);
      file_cache->saveSolution(problem,solution);
    }

    cout<<"solution : "<<solution<<endl;
    char *bufferOut = &solution[0];
    int is_send = send(client_socket, bufferOut, solution.length(), 0);
    if (is_send == -1) {
      cerr << "error sending massage to client" << endl;
    }
    cout << "bufferOut : " << bufferOut << endl;
  }
}
