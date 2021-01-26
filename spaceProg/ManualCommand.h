
#ifndef SPACEPROG_MANUALCOMMAND_H
#define SPACEPROG_MANUALCOMMAND_H

#include "ICommand.h"
#include "Engine.h"
class ManualCommand : public ICommand{
    int(Engine::*)(Args*) command;
    void execute(Args* args);
    ManualCommand();
};


#endif //SPACEPROG_MANUALCOMMAND_H
