//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_DFS_H
#define MILE_STONE2_DFS_H


#include "Searcher.h"
template<class T, class SOLUTION>
class DFS : public Searcher<T, SOLUTION> {
    int time = 0;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T>* searchable) {
        State<T>* initialState = searchable->getInitialState();
        State<T>* u;
        vector<State<T>*> allStates = searchable->getAllState();
        for (State<T>* u : allStates) {
            this->evaluatedNodes++;
            if (u->isWhite()) {
                dfsVisit(u, searchable);
            }
        }
    }
    void dfsVisit(State<T>* u, ISearchable<T>* searchable) {
        u->setGrey();
        u->setTrailCost(time);
        time++;
        vector<State<T>*> adj = searchable->getAllPossibleState(u);
        for (State<T>* v : adj) {
            if (v->isWhite()) {
                dfsVisit(v, searchable);
                v->setCameFrom(u);
            }
        }
        u->setBlack();
        time++;
    }
};


#endif //MILE_STONE2_DFS_H
