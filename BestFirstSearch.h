//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_BESTFIRSTSEARCH_H
#define MILE_STONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Compare.h"
#include <bits/stdc++.h>

using namespace std;

template<class T, class SOLUTION>
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
            if (n == searchable.getGoalState()) {
                // return the solution
                return searchable.printAll(n);
            }
            vector<State<T>> successors = searchable.getAllPossibleState(n);
            for (State<T> state : successors) {
                // check in closed
                if (closed.find(state) != closed.end()) {
                    inClosed = true;
                }
                // check in open
                inOpen = this->inOpenList(state);
                double possibleTrialCost = n.getTrialCost() + searchable.getWeightOfEdge(n, state);
                if (!inOpen && !inClosed) {
                    state.setCameFrom(n);
                    state.setTrailCost(possibleTrialCost);
                    this->openList.push(state);
                } else if (possibleTrialCost < state.getCost()) {
                    // the trial cost from n to state is better than the previous
                    state.setCameFrom(n);
                    state.setTrailCost(possibleTrialCost);
                    if (!this->inOpenList(state)) {
                        this->addOpenList(state);
                    } else {
                        // update in the priority queue
                        this->removeOpenList(state);
                        this->addOpenList(state);
                    }
                }
                inClosed = false;
            }
        }
    }
};


#endif //MILE_STONE2_BESTFIRSTSEARCH_H
