//
// Created by shirgold on 07/01/2020.
//
#include <string>
#include <limits>
#include "Point.h"

using namespace std;
#ifndef MILE_STONE2_STATE_H
#define MILE_STONE2_STATE_H

template<class T>
class State {
private:
    T state; // the representation of the state
    double cost; // the cost of the state
    double trailCost; // the cost from the initial state to this state
    State<T> *cameFrom; // the state we came from in the search
public:
    // constructor
    State(T state1) {
        this->state = state1;
        this->trailCost = numeric_limits<double>::infinity();
        this->cameFrom = nullptr;
        this->cost = 0;
    }
    // constructor
    State(T state1, double c) {
        this->trailCost = numeric_limits<double>::infinity();
        this->state = state1;
        this->cost = c;
        this->cameFrom = nullptr;
    }
    // operator == for State
    bool operator==(State<T> *&s) {
        return this->state == s;
    }
    // getters and setters
    void setCameFrom(State<T>* s) {
        this->cameFrom = s;
    }

    void setCost(double c) {
        this->cost = c;
    }

    double getCost() {
        return this->cost;
    }

    State<T> *getCameFrom() {
        return this->cameFrom;
    }

    void setTrailCost(double c) {
        this->trailCost = c;
    }

    double getTrialCost() const {
        return this->trailCost;
    }

    T getT() {
        return this->state;
    }

};

#endif //MILE_STONE2_STATE_H
