//
// Created by shirgold on 06/01/2020.
//

#ifndef MILE_STONE2_STRINGREVERSER_H
#define MILE_STONE2_STRINGREVERSER_H

#include <string>
#include <algorithm>
#include "Solver.h"

using namespace std;

class StringReverser : public Solver<char *, char *> {
public:
    virtual char *solve(char *problem) {
        string reverseP = (string) problem;
        reverse(reverseP.begin(), reverseP.end());
        char c[reverseP.length()];
        int i = 0;
        for (char a : reverseP) {
            c[i] = a;
            i++;
        }
        char *solution = c;
        return c;
    }
};


#endif //MILE_STONE2_STRINGREVERSER_H