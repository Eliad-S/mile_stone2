//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_SEARCHER_H
#define MILE_STONE2_SEARCHER_H

#include "Compare.h"
#include "ISearcher.h"
#include <queue>

using namespace std;

// T - the type of the representation of the state of the Isearchable
template<typename T, typename SOLUTION>
class Searcher : public ISearcher<T, SOLUTION> {
    int evaluatedNodes;
public:
    Searcher() {
        openList = new priority_queue<State<T>>();
        evaluatedNodes = 0;
    }

    int getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }

    virtual SOLUTION search(ISearchable<T> searchable) = 0;
    //virtual SOLUTION findSolution(State<T>) = 0;

protected:
    priority_queue<State<T>, vector<State<T>>, Compare<T>> openList;
    State<T> popOpenList() {
        evaluatedNodes++;
        if (openList.empty()) {
            return nullptr;
        }
        auto top = openList.top();
        openList.pop();
        return top;
    }
    bool inOpenList(State<T> state) {
        for (State<T> openState : this->openList) {
            if (state.equal(openState)) {
                return true;
            }
        }
        return false;
    }
    void addOpenList(State<T> state) {
        this->openList.push(state);
    }
    void removeOpenList(State<T> removeState) {
        vector<State<T>> allStatesInOpen;
        // insert to vector all the state except of the "removeState"
        for (State<T> s : this->openList) {
            this->openList.pop();
            if (!s.equal(removeState)) {
               allStatesInOpen.push_back(s);
            }
        }
        // insert again to the priority queue
        for (State<T> s : allStatesInOpen) {
            this->openList.push(s);
        }
    }
};

#endif //MILE_STONE2_SEARCHER_H
