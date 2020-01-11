//
// Created by shirgold on 08/01/2020.
//

#ifndef MILE_STONE2_COMPARE_H
#define MILE_STONE2_COMPARE_H

#include "State.h"
template <class T>
class Compare {
public:
    // compare two states according to the trial cost
    bool operator()(State<T> *s1, State<T> *s2) {
        return (s1->getTrialCost() > s2->getTrialCost());
    }

};
#endif //MILE_STONE2_COMPARE_H
