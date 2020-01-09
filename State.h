//
// Created by shirgold on 07/01/2020.
//
#include <string>
#include <limits>
using namespace std;
#ifndef MILE_STONE2_STATE_H
#define MILE_STONE2_STATE_H
template <class T>
class State {
private:
    T state;
    double cost;
    State<T> cameFrom;
public:
    State(T state1) {
        this->state = state1;
        this->cost = numeric_limits<double>::infinity();
    }
    State(T state1, double c) {
        this->state = state1;
        this->cost = c;
    }
    bool equal(State<T> s) {
        // check if they are equal
    }
    void setCameFrom(State<T> s) {
        this->cameFrom = s;
    }
    void setCost(double c) {
        this->cost = c;
    }
    double getCost() {
        return this->cost;
    }
    State<T> getCameFrom() {
        return this->cameFrom;
    }

};
#endif //MILE_STONE2_STATE_H
