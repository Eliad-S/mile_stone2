//
// Created by shirgold on 07/01/2020.
//
#ifndef MILE_STONE2_SEARCHABLE_H
#define MILE_STONE2_SEARCHABLE_H

#include <unordered_map>
#include "ISearchable.h"
#include <vector>
template<class T>
class Searchable : public ISearchable<T> {
protected:
    State<T> *goalState;
    State<T> *initialState;
    //unordered_map<pair<State<T>, State<T>>, double> edges;
    virtual string printOne(State<Point*>* s) = 0;
    string printAll(State<T>* goalState) {
        vector<string> steps;
        State<T>* son = goalState;
        State<T>* father = son->getCameFrom();
        while (father != nullptr) {
            string s = this->printOne(son);
            steps.push_back(s);
            son = father;
            father = son->getCameFrom();
        }
        string solution = "";
        for (string s : steps) {
            solution = s + solution;
        }
        return solution;

    }
public:
    Searchable() {}
    virtual State<T> getInitialState() {
        return this->initialState;
    }
    virtual State<T> getGoalState() {
        return this->goalState;
    }
    virtual list<State<T>> getAllPossibleState(State<T> s) = 0;
    virtual void setInitialState(State<T> initial) {
        this->initialState = initial;
    }
    virtual void setGoalState(State<T> goal) {
        this->goalState = goal;
    }
    virtual double getWeightOfEdge (State<T> e1, State<T> e2) {
        auto edge = this->edges.find({e1, e2});
        if (edge != this->edges.end()) {
            return edge.second;
        } else {
            // error
        }
    }
};
#endif //MILE_STONE2_SEARCHABLE_H