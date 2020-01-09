//
// Created by shirgold on 08/01/2020.
//

#ifndef MILE_STONE2_COMPARE_H
#define MILE_STONE2_COMPARE_H

#include "State.h"
template <class T>
class Compare {
    bool operator()(const State<T> *s1, const State<T> *s2) {
        return (s1->getCost() > s2->getCost());
    }

};
#endif //MILE_STONE2_COMPARE_H
