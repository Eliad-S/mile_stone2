//
// Created by eliadsellem on 1/6/20.
//
#include <unordered_map>
using namespace std;
#ifndef MILE_STONE2__FILECACHEMANAGER_H_
#define MILE_STONE2__FILECACHEMANAGER_H_
template<typename P, typename S>
class FileCacheManager {
    // <problem, solution>
    unordered_map<P, S> cache;
public:
    /*
     * returns true if the solution of the problem
     * is in the cache and false otherwise.
     */
    virtual bool isSolved(P problem) {
        return cache.find(problem) != cache.end();
    }
    /*
     * returns the solution of the given problem.
     */
    virtual S getSolution(P problem) {
        auto solution = cache.find(problem);
        if (solution != cache.end()) {
            return solution;
        }
        return nullptr;
    }
    /*
     * saves new solution to new problem.
     */
    virtual void saveSolution(P problem, S solution) {
        cache[problem] = solution;
    }
};

#endif //MILE_STONE2__FILECACHEMANAGER_H_
