//
// Created by shirgold on 15/01/2020.
//

#ifndef MILE_STONE2_BOOT_H
#define MILE_STONE2_BOOT_H

#include "MySerialServer.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
namespace Boot {
    class Main {
    public:
        void main(int port) {
            MyParallelServer *s = new MyParallelServer();
            CacheManager<string,string>* fileCache = new FileCacheManager();
            Searcher<Point *, string> *aStar = new AStar<Point *, string>();
            Solver<ISearchable<Point *> *, string> *solverAStar = new SolverSearch<string, Point *>(aStar);
            ClientHandler *c = new MyClientHandler(solverAStar, fileCache);
            s->open(port, c);
            delete (fileCache);
            delete (solverAStar);
            delete (c);
            delete (aStar);

        }
    };
}





#endif //MILE_STONE2_BOOT_H
