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
            Server* s = new MySerialServer();
            Solver<string,string>* solver = new StringReverser();
            CacheManager<string,string>* cache = new FileCacheManager();
            ClientHandler* c = new MyTestClientHandler(solver, cache);
            s->open(port, c);
        }
    };
}





#endif //MILE_STONE2_BOOT_H
