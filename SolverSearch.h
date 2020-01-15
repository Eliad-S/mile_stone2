//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__SOLVERSEARCH_H_
#define MILE_STONE2__SOLVERSEARCH_H_

#include <iostream>
#include "Solver.h"
#include "Searcher.h"

//can adding another tamplate to make the point genery .
template<typename P, typename S, typename T>
class SolverSearch : public Solver<P, S> {
    ISearcher<T, S> *searcher;
public:
    // constructor
    SolverSearch(ISearcher<T, S> *s) {
        this->searcher = s;
    }
    /*
     * solve the problem by the search algorithm
     */
    virtual S solve(P problem) {
      cout << this->searcher->search(problem)<<endl;
        return this->searcher->search(problem);
    }
    Solver<P,S>* clone(){
      return new SolverSearch(searcher->clone());
    }
};

#endif //MILE_STONE2__SOLVERSEARCH_H_
