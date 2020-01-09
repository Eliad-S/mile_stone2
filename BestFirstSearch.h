//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_BESTFIRSTSEARCH_H
#define MILE_STONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Compare.h"
#include <bits/stdc++.h>
using namespace std;
template <class T, class SOLUTION>
class BestFirstSearch : public Searcher<T, SOLUTION> {
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T> searchable) {
        bool inClosed = false, inOpen;
        this->openList.push(searchable.getInitialState());
        unordered_set<State<T>> closed;
        while (this->openList.size() > 0) {
            State<T> n = this->popOpenList();
            closed.insert(n);
            if (n.equal(searchable.getGoalState())) {
                // return the solution
            }
            list<State<T>> successors = searchable.getAllPossibleState(n);
            for (State<T> state : successors) {
                for (State<T> closedState : closed) {
                    if (state.equal(closedState)) {
                        inClosed = true;
                    }
                }
                inOpen = this->inOpenList(state);
                double possibleCost = n.getCost() + searchable.getWeightOfEdge(n, state);
                if (!inOpen && !inClosed) {
                    state.setCameFrom(n);
                    state.setCost(possibleCost);
                    this->openList.push(state);
                } else if (possibleCost < state.getCost()) {
                    state.setCameFrom(n);
                    state.setCost(possibleCost);
                    if (!this->inOpenList(state)) {
                        this->addOpenList(state);
                    } else {
                        this->removeOpenList(state);
                        this->addOpenList(state);
                    }
                }
            }
        }
    }
};


#endif //MILE_STONE2_BESTFIRSTSEARCH_H
