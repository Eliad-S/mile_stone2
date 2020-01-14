//
// Created by shirgold on 13/01/2020.
//

#ifndef MILE_STONE2_MYPARALLELSERVER_H
#define MILE_STONE2_MYPARALLELSERVER_H
#include "Server.h"
using namespace server_side;
class MyParallelServer : public Server {
public:
    virtual void open(int p, ClientHandler* c) {
    }
    virtual void stop() {
    }
};


#endif //MILE_STONE2_MYPARALLELSERVER_H
