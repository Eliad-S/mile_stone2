//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_DFS_H
#define MILE_STONE2_DFS_H

#include "Searcher.h"
#include <set>

template<class T, class SOLUTION>
class DFS : public Searcher<T, SOLUTION> {
    int time = 0;
    set<State<T> *> used;
    bool flag = false;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T> *searchable) {
        searchable->nullify();
        used.clear();
        this->evaluatedNodes = 0;
        time = 0;
        State<T> *initialState = searchable->getInitialState();
        dfsVisit(initialState, searchable);
        if (!flag) {
            return "no solution";
        }
        // for the next running
        flag = false;
        updateSolutionWithCost(searchable->getGoalState());
        // return the solution
        return this->printAll(searchable->getGoalState(), searchable);
    }

    void dfsVisit(State<T> *u, ISearchable<T> *searchable) {
        this->evaluatedNodes++;
        used.insert(u);
        u->setTrailCost(time);
        time++;
        vector<State<T> *> adj = searchable->getAllPossibleState(u);
        // for all the neighbors of u:
        for (State<T> *v : adj) {
            if (v->getCost() < 0) {
                continue;
            }
            if (u == searchable->getGoalState()) {
                flag = true;
                return;
            }
            if (used.find(v) == used.end()) {
                dfsVisit(v, searchable);
                v->setCameFrom(u);
            }
        }
        time++;
    }

    double updateSolutionWithCost(State<T>* s) {
        if (s->getCameFrom() == nullptr) {
            s->setTrailCost(s->getCost());
        } else {
            double cost = s->getCost() + updateSolutionWithCost(s->getCameFrom());
            s->setTrailCost(cost);
        }
    }

    ISearcher<T, SOLUTION> *clone() {
        return new DFS();
    }
};

#endif //MILE_STONE2_DFS_H
