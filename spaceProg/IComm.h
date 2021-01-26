//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_ICOMM_H
#define SPACEPROG_ICOMM_H
#include "Args.h"

class IComm {
public:
    virtual void execute(Args* args) = 0;
    virtual ~IComm(){};
};


#endif //SPACEPROG_ICOMM_H
