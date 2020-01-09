//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_ISEARCHABLE_H
#define MILE_STONE2_ISEARCHABLE_H

#include "State.h"
#include <list>
#include <string.h>
using namespace std;
template <class T>
class ISearchable {
    virtual State<T> getInitialState() = 0;
    virtual State<T> getGoalState() = 0;
    virtual list<State<T>> getAllPossibleState(State<T> s) = 0;
    virtual void setInitialState(State<T> initial) = 0;
    virtual void setGoalState(State<T> goal) = 0;
    virtual double getWeightOfEdge (State<T> e1, State<T> e2) = 0;
};


#endif //MILE_STONE2_ISEARCHABLE_H
