//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_ASTAR_H
#define MILE_STONE2_ASTAR_H

#include "Searcher.h"
template<class T, class SOLUTION>
class AStar : public Searcher<T, SOLUTION> {
public:
    SOLUTION search(ISearchable<T>* searchable) {
        this->addOpenList(searchable->getInitialState());
        // while the priority queue is not empty
        while (this->openList.size() > 0) {
            State<T>* n = this->popOpenList();
            if (n == searchable->getGoalState()) {
                // return the solution
                return searchable->printAll(n);
            }
            vector<State<T>*> successors = searchable->getAllPossibleState(n);
            for (State<T>* state : successors) {
                double possibleTrialCost = n->getTrialCost() + state->getCost();
                if (possibleTrialCost < state->getTrialCost()) {
                    state->setCameFrom(n);
                    state->setTrailCost(possibleTrialCost);
                    if (!inOpenList(state)) {
                        addOpenList(state);
                    }
                }
            }
        }
    }
};


#endif //MILE_STONE2_ASTAR_H
