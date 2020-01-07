//
// Created by shirgold on 07/01/2020.
//
#include "Solver.h"
#ifndef MILE_STONE2_SEARCHABLE_H
#define MILE_STONE2_SEARCHABLE_H
template<typename P, typename S>
class Searchable : public Solver<P, S> {
//virtual Solution search(ISearchable searchable) = 0;

virtual int getNumberOfNodesEvaluated() = 0;

};
#endif //MILE_STONE2_SEARCHABLE_H
