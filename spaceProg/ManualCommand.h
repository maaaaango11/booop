
#ifndef SPACEPROG_MANUALCOMMAND_H
#define SPACEPROG_MANUALCOMMAND_H

#include "IComm.h"
#include "Engine.h"
class ManualCommand : public IComm{
    //int(Engine::*)(Args*) command;
    void execute(Args* args);
    ManualCommand();
};


#endif //SPACEPROG_MANUALCOMMAND_H
