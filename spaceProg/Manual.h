
#ifndef SPACEPROG_MANUAL_H
#define SPACEPROG_MANUAL_H

#include "IMode.h"
#include "Parser.h"
#include "ICommand.h"
#include <vector>

class Manual : public IMode{
private:
   std::vector<std::pair<std::string, ICommand*>> commands;
    Parser parser;
public:
    Manual(Parser& p);
    void nextMove();
};


#endif //SPACEPROG_MANUAL_H
