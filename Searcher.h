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
    // constructor
    Searcher() {
        evaluatedNodes = 0;
    }

    int getNumberOfNodesEvaluated() {
        return evaluatedNodes;
    }

    virtual SOLUTION search(ISearchable<T>* searchable) = 0;

protected:
    priority_queue<State<T> *, vector<State<T> *>, Compare<T>> openList;
    /*
     * the function pop from the queue the state with the greatest priority
     * and updates the evaluated Nodes.
     */
    State<T>* popOpenList() {
        evaluatedNodes++;
        if (openList.empty()) {
            return nullptr;
        }
        auto top = openList.top();
        openList.pop();
        return top;
    }
    /*
     * the function checks if the state is in the OpenList (queue)
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
        // insert again to the priority queue
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
    /*
     * the function removes the state from the OpenList (queue)
     */
    void removeOpenList(State<T>* removeState) {
        vector<State<T>*> allStatesInOpen;
        // insert to vector all the state except of the "removeState"
        while (!this->openList.empty()) {
            State<T>* s = this->openList.top();
            this->openList.pop();
            if (!(s == removeState)) {
               allStatesInOpen.push_back(s);
            }
        }
        // insert again to the priority queue
        for (State<T>* s : allStatesInOpen) {
            this->openList.push(s);
        }
    }
};

#endif //MILE_STONE2_SEARCHER_H
