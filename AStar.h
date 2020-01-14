//
// Created by shirgold on 12/01/2020.
//

#ifndef MILE_STONE2_ASTAR_H
#define MILE_STONE2_ASTAR_H

#include "Searcher.h"

template<class T, class SOLUTION>
class AStar : public Searcher<T, SOLUTION> {
  priority_queue<State<T> *, vector<State<T> *>, CompareFScore<T>> openList;
 public:
  // Searcher's abstract method overriding
  SOLUTION search(ISearchable<T> *searchable) {
    searchable->nullify();
    clearQueue();
    this->evaluatedNodes = 0;
    bool inClosed;
    //Initialize the open list with initial state.
    State<T> *initialState = searchable->getInitialState();
    this->addOpenList(initialState);
    initialState->setTrailCost(0);
    initialState->setFScore(0);
    //initial closed set.
    unordered_set<State<T> *> closed;

    // while the priority queue is not empty
    while (this->openList.size() > 0) {
      State<T> *q = this->popOpenList();
      // we arrive to he goal state
      if (q == searchable->getGoalState()) {
        // return the solution
         string s = searchable->printAll(q);
        return s;
      }
      closed.insert(q);
      vector<State<T> *> successors = searchable->getAllPossibleState(q);
      for (State<T> *state : successors) {
        inClosed = false;
        if(state->getCost()<0) {
          continue;
        }
        double possibleTrialCost = q->getTrialCost() + state->getCost();
        if (closed.find(state) != closed.end()) {
          inClosed = true;
        }
        if (inClosed || possibleTrialCost >= state->getTrialCost()) {
          continue;
        }
        // if the current way is better than the previous:
        if (!inOpenList(state) || possibleTrialCost < state->getTrialCost()) {
          state->setCameFrom(q);
          state->setTrailCost(possibleTrialCost);
          state->setFScore(possibleTrialCost + heuristicFunc(searchable, state));
          if (!inOpenList(state)) {
            addOpenList(state);
          }
        }
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

  double heuristicFunc(ISearchable<T> *searchable, State<T> *state) {
    double dx = abs(state->getT()->getX() - searchable->getInitialState()->getT()->getX());
    double dy = abs(state->getT()->getY() - searchable->getInitialState()->getT()->getY());
    return dx + dy;
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
   * the function inserts the state to the OpenList (queue)
   */
  void addOpenList(State<T> *state) {
    this->openList.push(state);
  }

  void clearQueue() {
    while (!openList.empty()) {
      openList.pop();
    }
  }
};

#endif //MILE_STONE2_ASTAR_H
