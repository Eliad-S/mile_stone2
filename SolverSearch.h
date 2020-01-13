//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__SOLVERSEARCH_H_
#define MILE_STONE2__SOLVERSEARCH_H_

#include <iostream>
#include "Solver.h"
#include "Searcher.h"

template<typename P, typename S, typename T>
class SolverSearch : public Solver<P, S> {
    Searcher<T, S> *searcher;
public:
    // constructor
    SolverSearch(Searcher<T, S> *s) {
        this->searcher = s;
    }
    /*
     * solve the problem by the search algorithm
     */
    virtual S solve(P problem) {
      cout << this->searcher->search(problem)<<endl;
        return this->searcher->search(problem);
    }
};

#endif //MILE_STONE2__SOLVERSEARCH_H_
