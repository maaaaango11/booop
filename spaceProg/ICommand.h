//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_ICOMMAND_H
#define SPACEPROG_ICOMMAND_H
#include "Args.h"

class ICommand {
public:
    virtual void execute(Args* args) = 0;
    virtual ~ICommand(){};
};


#endif //SPACEPROG_ICOMMAND_H
