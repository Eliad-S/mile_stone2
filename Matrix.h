//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__MATRIX_H_
#define MILE_STONE2__MATRIX_H_

#include "Searchable.h"
#include "Point.h"
class Matrix : public Searchable<Point*> {
  vector<vector<State<Point*>*>> vertexes;

 public:
  Matrix(vector<vector<State<Point*>*>>& v) {
    vertexes = v;
  }
   virtual string printOne(State<Point*>* s) {
    State<Point*>* father = s->getCameFrom();
    Point* fatherPoint = father->getT();
    Point* sonPoint = s->getT();
    if(fatherPoint->getX() > sonPoint->getX()) {
      return "UP (" + to_string(s->getTrialCost()) + "), ";
    }
    if(fatherPoint->getX() < sonPoint->getX()) {
      return "DOWN (" + to_string(s->getTrialCost()) + "), ";
    }
    if(fatherPoint->getY() > sonPoint->getY()) {
      return "LEFT (" + to_string(s->getTrialCost()) + "), ";
    }
    if(fatherPoint->getY() < sonPoint->getY()) {
      return "RIGHT (" + to_string(s->getTrialCost()) + "), ";
    }
    return "not good";
  }
  virtual vector<State<Point*>*> getAllPossibleState(State<Point*>* s) {
    int size = this->vertexes.front().size() - 1;
    vector<State<Point*>*> sons;
    Point* p = s->getT();
    if (p->getX() != 0) {
      sons.push_back(vertexes[p->getX() - 1][p->getY()]);
    }
    if (p->getX() != size) {
      sons.push_back(vertexes[p->getX() + 1][p->getY()]);
    }
    if (p->getY() != 0) {
      sons.push_back(vertexes[p->getX()][p->getY() - 1]);
    }
    if (p->getY() != size) {
      sons.push_back(vertexes[p->getX()][p->getY() + 1]);
    }
    return sons;
  }
  virtual vector<State<Point*>*> getAllState() {
      vector<State<Point*>*> allStates;
      for (vector<State<Point*>*> v : this->vertexes) {
          for (State<Point*>* s : v) {
              allStates.push_back(s);
          }
      }
      return allStates;
  }

};

#endif //MILE_STONE2__MATRIX_H_
