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
    set<State<T>*> used;
    bool flag = false;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T>* searchable) {
        State<T>* initialState = searchable->getInitialState();
        State<T>* u;
        vector<State<T>*> allStates = searchable->getAllState();
        for (State<T>* u : allStates) {
            this->evaluatedNodes++;
            if (used.find(u) == used.end()) {
                dfsVisit(u, searchable);
            }
        }
        searchable->nullify();
        if (!flag) {
            return "no solution";
        }
        // return the solution
        return searchable->printAll(searchable->getGoalState());
    }
    void dfsVisit(State<T>* u, ISearchable<T>* searchable) {
        used.insert(u);
        u->setTrailCost(time);
        time++;
        vector<State<T>*> adj = searchable->getAllPossibleState(u);
        for (State<T>* v : adj) {
            if (used.find(v) == used.end()) {
                dfsVisit(v, searchable);
                v->setCameFrom(u);
            }
            if (v == searchable->getGoalState()) {
                flag = true;
            }
        }
        time++;
    }
};


#endif //MILE_STONE2_DFS_H
