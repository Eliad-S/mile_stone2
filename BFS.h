//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_BFS_H
#define MILE_STONE2_BFS_H

#include "Searcher.h"
template<class T, class SOLUTION>
class BFS : public Searcher<T, SOLUTION> {
    queue<State<T>*> myQueue;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T>* searchable) {
        State<T>* initialState = searchable->getInitialState();
        initialState->setTrailCost(0);
        initialState->setGrey();
        addToQueue(initialState);
        while (!myQueue.empty()) {
            State<T>* u = popQueue();
            vector<State<T>*> adj = searchable->getAllPossibleState(u);
            for (State<T>* v : adj) {
                if (v->isWhite()) {
                    v->setGrey();
                    v->setTrailCost(u->getTrialCost() + 1);
                    v->setCameFrom(u);
                    addToQueue(v);
                }
            }
            u->setBlack();
        }
    }
    State<T>* popQueue() {
        this->evaluatedNodes++;
        if (myQueue.empty()) {
            return nullptr;
        }
        auto top = myQueue.front();
        myQueue.pop();
        return top;
    }
    /*
     * the function inserts the state to the queue
     */
    void addToQueue(State<T>* state) {
        myQueue.push(state);
    }
};


#endif //MILE_STONE2_BFS_H
