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
  allProblemInString = "";
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
      allProblem = splitLines(allProblemInString);
      if (file_cache->isSolved(allProblemInString)) {
        solution = file_cache->getSolution(allProblemInString);
        cout << "from file: " << solution << endl;
      } else {
        //create matrix
        ISearchable<Point *> *matrix = createMatrix();
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
  }
}

ISearchable<Point *> *MyClientHandler::createMatrix() {
  int size = allProblem.size();
  vector<vector<State<Point *> *>> vertexes;
  string line;
  string substr = "";
  int pos = 0;
  int i, j = 0;
  for (i = 0; i < size - 2; i++) {
    line = allProblem[i];
    vector<State<Point *> *> row;
    while (true) {
      if (line.find(",") < line.find("\n")) {
        substr = line.substr(pos, line.find(","));
        double val = stod(substr);
        Point *p = new Point(i, j);
        State<Point *> *t = new State<Point *>(p, val);
        row.push_back(t);
        line = line.substr(line.find(",") + 1);
        j++;
      } else {
        substr = line.substr(pos, line.find("\n"));
        double val = stof(substr);
        Point *p = new Point(i, j);
        State<Point *> *t = new State<Point *>(p, val);
        row.push_back(t);
        vertexes.push_back(row);
        j = 0;
        break;
      }
    }
  }
  ISearchable<Point *> *matrix = new Matrix(vertexes);
  //get start point
  double x, y;
  split(allProblem[i], &x, &y);
  matrix->setInitialState(vertexes[x][y]);
  //get goal point
  split(allProblem[i + 1], &x, &y);
  matrix->setGoalState(vertexes[x][y]);
  return matrix;

}

void MyClientHandler::split(string line, double *x, double *y) {
  string substr = "";
  double val = 0;
  int pos = 0;
  substr = line.substr(pos, line.find(","));
  val = stod(substr);
  *x = val;
  line = line.substr(line.find(",") + 1);
  substr = line.substr(pos, line.find("\n"));
  val = stod(substr);
  *y = val;
}

vector<string> MyClientHandler::splitLines(string problem) {
  vector<string> lines;
  string line = "";
  for (char c:problem) {
    if (c == ' ') {
      continue;
    }
    line += c;
    if (c == '\n') {
      lines.push_back(line);
      line = "";
    }
  }
  lines.pop_back();
  return lines;
}
