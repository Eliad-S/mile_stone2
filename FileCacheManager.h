//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__FILECACHEMANAGER_H_
#define MILE_STONE2__FILECACHEMANAGER_H_
template<typename P, typename S>
class FileCacheManager {
public:
    virtual bool isSolved(P problem);
    virtual S getSolution(P problem);
    virtual void saveSolution(P problem, S solution);
};

#endif //MILE_STONE2__FILECACHEMANAGER_H_
