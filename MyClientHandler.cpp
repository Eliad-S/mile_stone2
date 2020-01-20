//
// Created by eliadsellem on 1/9/20.
//

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include "State.h"
#include "Point.h"
#include "ISearchable.h"
#include "Matrix.h"

void MyClientHandler::handleClient(int client_socket) {
  int counter = 0;
  string allProblemInString = "";
  int flag = 0;
  string solution;
  while (true) {
    char buffer[6000] = {0};
    //receive massage
    int valRead = read(client_socket, buffer, 6000);

    if (valRead == 0) {
      break;
    }
    string problem = string(buffer);
    problem = problem.substr(0, valRead);
    cout << "new line" << endl;
    allProblemInString += problem;

    if (allProblemInString.find("end") < allProblemInString.size()) {
      cout << "endddd" << endl;
      if (file_cache->isSolved(allProblemInString)) {
        solution = file_cache->getSolution(allProblemInString);
        cout << "from file: " << solution << endl;
      } else {
        //create matrix
        ISearchable<Point *> *matrix = new Matrix(allProblemInString);
        solution = solver->solve(matrix);
        file_cache->saveSolution(allProblemInString, solution);
      }
    } else {
      continue;
    }

    cout << "before loop" << endl;
    //write the massage into file
    char *bufferOut = &solution[0];
    int is_send = send(client_socket, bufferOut, solution.length(), 0);
    if (is_send == -1) {
      cerr << "error sending massage to client" << endl;
    }
    cout << "bufferOut : " << solution << endl;
    break;
  }
  close(client_socket);
}
ClientHandler *MyClientHandler::clone() {
  ClientHandler *c = new MyClientHandler(solver->clone(), file_cache);
  return c;
}


