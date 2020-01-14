//
// Created by shirgold on 07/01/2020.
//

#ifndef MILE_STONE2_SEARCHER_H
#define MILE_STONE2_SEARCHER_H

#include "CompareFScore.h"
#include "ISearcher.h"
#include <queue>

using namespace std;

// T - the type of the representation of the state of the Isearchable
template<typename T, typename SOLUTION>
class Searcher : public ISearcher<T, SOLUTION> {
protected:
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
};

#endif //MILE_STONE2_SEARCHER_H
