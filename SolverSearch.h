//
// Created by eliadsellem on 1/9/20.
//

#ifndef MILE_STONE2__SOLVERSEARCH_H_
#define MILE_STONE2__SOLVERSEARCH_H_

#include "Solver.h"
#include "Searcher.h"
template<typename P, typename S,typename T>
class SolverSearch: public Solver<P, S> {
  Searcher<P, S> searcher;
 public:
  SolverSearch(Searcher<T, S> s) {
    this->searcher = s;
  }
  virtual S solve(P problem) {
    return this->searcher.search(problem);
  }
};

#endif //MILE_STONE2__SOLVERSEARCH_H_
