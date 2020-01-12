//
// Created by shirgold on 07/01/2020.
//
#include <string>
#include <limits>
#include "Point.h"

using namespace std;
#ifndef MILE_STONE2_STATE_H
#define MILE_STONE2_STATE_H
#define BLACK 3
#define GREY 2
#define WHITE 1
template<class T>
class State {
private:
    T state; // the representation of the state
    double cost; // the cost of the state
    double trailCost; // the cost from the initial state to this state
    State<T> *cameFrom; // the state we came from in the search
    int color;
public:
    // constructor
    State(T state1) {
        this->state = state1;
        this->trailCost = numeric_limits<double>::infinity();
        this->cameFrom = nullptr;
        this->cost = 0;
        this->color = WHITE;
    }
    // constructor
    State(T state1, double c) {
        this->trailCost = numeric_limits<double>::infinity();
        this->state = state1;
        this->cost = c;
        this->cameFrom = nullptr;
        this->color = WHITE;
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
    void setBlack() {
        this->color = BLACK;
    }
    void setWhite() {
        this->color = WHITE;
    }
    void setGrey() {
        this->color = GREY;
    }
    bool isBlack() {
        return this->color == BLACK;
    }
    bool isWhite() {
        return this->color == WHITE;
    }
    bool isGrey() {
        return this->color == GREY;
    }

};

#endif //MILE_STONE2_STATE_H
