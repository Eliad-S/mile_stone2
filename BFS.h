//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_BFS_H
#define MILE_STONE2_BFS_H

#include "Searcher.h"
template<class T, class SOLUTION>
class BFS : public Searcher<T, SOLUTION> {
    queue<State<T>*> queue;
public:
    SOLUTION search(ISearchable<T>* searchable) {
        State<T>* initialState = searchable->getInitialState();
        initialState->setTrailCost(0);
        initialState->setGrey();
        queue.push(initialState);
        while (!queue.empty()) {
            State<T>* u = queue.front();
            queue.pop();
            vector<State<T>*> adj = searchable->getAllPossibleState(u);
            for (State<T>* v : adj) {
                if (v->isWhite()) {
                    v->setGrey();
                    v->setTrailCost(u->getTrialCost() + 1);
                    v->setCameFrom(u);
                    queue.push(v);
                }
            }
            u->setBlack();
        }
    }
};


#endif //MILE_STONE2_BFS_H
