//
// Created by shirgold on 06/01/2020.
//

#ifndef MILE_STONE2_STRINGREVERSER_H
#define MILE_STONE2_STRINGREVERSER_H

#include <string>
#include <algorithm>
#include "Solver.h"
using namespace std;
class StringReverser : public Solver<char *, const char *> {
public:
    virtual const char* solve(char* problem) {
        string p = (string) problem;
        reverse(p.begin(), p.end());
        const char *solution = p.c_str();
        return solution;
    }
};


#endif //MILE_STONE2_STRINGREVERSER_H