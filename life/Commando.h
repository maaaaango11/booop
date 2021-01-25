//
// Created by МаксиМ on 19.11.2020.
//
#include <iostream>
#include "Args.h"
#ifndef LIFE_COMMANDO_H
#define LIFE_COMMANDO_H


class Commando {
private:
    Args* args = new Args();
public:
    Args* readStrRetArgs();
    Args* getArgs();
    ~Commando();
};


#endif //LIFE_COMMANDO_H