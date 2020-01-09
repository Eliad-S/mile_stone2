//
// Created by eliadsellem on 1/9/20.
//

#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include "MyClientHandler.h"
#include <vector>
#include "State.h"
#include "Point.h"
#include "ISearchable.h"
void MyClientHandler:: handleClient(int server_socket){
  while(true) {
    char buffer[1500] = {0};
    //receive massage
    int valRead = read(server_socket, buffer, 1500);
    if(valRead == 0) {
      break;
    }
    string problem = string(buffer);
    problem = problem.substr(0, valRead);
    string solution;
    if (problem.compare("End") == 0) {
      cout << "endddd" << endl;
      if(file_cache->isSolved(problem)) {
        solution = file_cache->getSolution(problem);
        cout<<"from file: "<<solution<<endl;
      }else {
        //create matrix
        ISearchable<Point>* matrix = createMatrix(problem);
        solution = solver->solve(matrix);
        file_cache->saveSolution(problem,solution);
      }
      close(server_socket);
    }else{
      allProblem = allProblem + problem;
      continue;
    }
    //write the massage into file

    char *bufferOut = &solution[0];
    int is_send = send(server_socket, bufferOut, solution.length(), 0);
    if (is_send == -1) {
      cerr << "error sending massage to client" << endl;
    }
    cout << "bufferOut : " << solution << endl;
  }
}