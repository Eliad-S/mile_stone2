//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_BESTFIRSTSEARCH_H
#define MILE_STONE2_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "CompareTrail.h"
#include <bits/stdc++.h>

using namespace std;

template<class T, class SOLUTION>
class BestFirstSearch : public Searcher<T, SOLUTION> {
  priority_queue<State<T> *, vector<State<T> *>, CompareTrail<T>> openList;
 public:
  // Searcher's abstract method overriding
  SOLUTION search(ISearchable<T> *searchable) {
    searchable->nullify();
    clearQueue();
    this->evaluatedNodes = 0;
    bool inClosed = false, inOpen;
    State<T> *initialState = searchable->getInitialState();
    initialState->setTrailCost(initialState->getCost());
    this->addOpenList(initialState);
    unordered_set<State<T> *> closed;
    // while the priority queue is not empty
    while (this->openList.size() > 0) {
      State<T> *n = this->popOpenList();
      closed.insert(n);
      if (n == searchable->getGoalState()) {
        // return the solution
        return searchable->printAll(n);
      }
      vector<State<T> *> successors = searchable->getAllPossibleState(n);
      for (State<T> *state : successors) {
        if(state->getCost()<0){
          continue;
        }
        // check in closed
        if (closed.find(state) != closed.end()) {
          inClosed = true;
        }
        // check in open
        inOpen = this->inOpenList(state);
        double possibleTrialCost = n->getTrialCost() + state->getCost();
        if (!inOpen && !inClosed) {
          state->setCameFrom(n);
          state->setTrailCost(possibleTrialCost);
          this->addOpenList(state);
          // if the current way is better than the previous:
        } else if (possibleTrialCost < state->getTrialCost()) {
          state->setCameFrom(n);
          state->setTrailCost(possibleTrialCost);
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
    return "no solution";
  }
  /*
   * the function pop from the queue the state with the greatest priority
   * and updates the evaluated Nodes.
   */
  State<T> *popOpenList() {
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
  bool inOpenList(State<T> *state) {
    bool inOpen = false;
    vector<State<T> *> allStatesInOpen;
    while (!this->openList.empty()) {
      State<T> *s = this->openList.top();
      this->openList.pop();
      if (s == state) {
        inOpen = true;
      }
      allStatesInOpen.push_back(s);
    }
    // insert again to the priority myQueue
    for (State<T> *s : allStatesInOpen) {
      this->openList.push(s);
    }
    return inOpen;
  }
  /*
   * the function inserts the state to the OpenList (myQueue)
   */
  void addOpenList(State<T> *state) {
    this->openList.push(state);
  }
  /*
   * the function removes the state from the OpenList (myQueue)
   */
  void removeOpenList(State<T> *removeState) {
    vector<State<T> *> allStatesInOpen;
    // insert to vector all the state except of the "removeState"
    while (!this->openList.empty()) {
      State<T> *s = this->openList.top();
      this->openList.pop();
      if (!(s == removeState)) {
        allStatesInOpen.push_back(s);
      }
    }
    // insert again to the priority myQueue
    for (State<T> *s : allStatesInOpen) {
      this->openList.push(s);
    }
  }
  void clearQueue() {
    while (!openList.empty()) {
      openList.pop();
    }
  }
  ISearcher<T, SOLUTION>* clone(){
    return new BestFirstSearch();
  }
};
#endif //MILE_STONE2_BESTFIRSTSEARCH_H
