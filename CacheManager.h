//
// Created by eliadsellem on 1/6/20.
//

#ifndef MILE_STONE2__CACHEMANAGER_H_
#define MILE_STONE2__CACHEMANAGER_H_

#endif //MILE_STONE2__CACHEMANAGER_H_
template<typename P, typename S>
class CacheManager {
    virtual bool isSolved(P problem);
    virtual S getSolution(P problem);
    virtual void saveSolution(P problem, S solution);
};