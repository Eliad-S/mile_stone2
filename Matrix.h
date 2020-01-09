//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__MATRIX_H_
#define MILE_STONE2__MATRIX_H_

#include "Searchable.h"
#include "Point.h"
class Matrix : public Searchable<Point*> {
  vector<vector<State<Point*>*>> vertexes;
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


  }

};

#endif //MILE_STONE2__MATRIX_H_
