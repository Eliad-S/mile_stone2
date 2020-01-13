//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_ASTAR_H
#define MILE_STONE2_ASTAR_H

#include "Searcher.h"
template<class T, class SOLUTION>
class AStar : public Searcher<T, SOLUTION> {
    priority_queue<State<T> *, vector<State<T> *>, Compare<T>> openList;
public:
    // Searcher's abstract method overriding
    SOLUTION search(ISearchable<T>* searchable) {
        this->addOpenList(searchable->getInitialState());
        // while the priority queue is not empty
        while (this->openList.size() > 0) {
            State<T>* n = this->popOpenList();
            // we arrive to he goal state
            if (n == searchable->getGoalState()) {
                // return the solution
                return searchable->printAll(n);
            }
            vector<State<T>*> successors = searchable->getAllPossibleState(n);
            // for all the neighbors of n:
            for (State<T>* state : successors) {
                double possibleTrialCost = n->getTrialCost() + state->getCost();
                // if the current way is better than the previous:
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
    /*
     * the function pop from the queue the state with the greatest priority
     * and updates the evaluated Nodes.
     */
    State<T>* popOpenList() {
        this->evaluatedNodes++;
        if (openList.empty()) {
            return nullptr;
        }
        auto top = openList.top();
        openList.pop();
        return top;
    }
    /*
     * the function checks if the state is in the OpenList (myQueue)
     */
    bool inOpenList(State<T>* state) {
        bool inOpen = false;
        vector<State<T>*> allStatesInOpen;
        while (!this->openList.empty()) {
            State<T>* s = this->openList.top();
            this->openList.pop();
            if (s == state) {
                inOpen = true;
            }
            allStatesInOpen.push_back(s);
        }
        // insert again to the priority myQueue
        for (State<T>* s : allStatesInOpen) {
            this->openList.push(s);
        }
        return inOpen;
    }
    /*
     * the function inserts the state to the OpenList (queue)
     */
    void addOpenList(State<T>* state) {
        this->openList.push(state);
    }
};


#endif //MILE_STONE2_ASTAR_H
