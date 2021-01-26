//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_PARSER_H
#define SPACEPROG_PARSER_H

#include "Args.h"
#include <iostream>

class Parser {
private:
    Args* args = new Args;
public:
    void parse();
    Args* getArgs();
};


#endif //SPACEPROG_PARSER_H
