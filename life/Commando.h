//
// Created by МаксиМ on 19.11.2020.
//

#ifndef LIFE_COMMANDO_H
#define LIFE_COMMANDO_H

#include <vector>
#include <iostream>

class Args{

};

class Commando {
private:
    std::vector<std::pair<std::string, int(Commando::*)(Args) >> commands;
public:
    void getCommand();
    Commando();
    int reset(Args args); //0
    int set(Args args); //int x int y
    int clear(Args args); // int x int y
    int step(Args args); //0
    int back(Args args); //0
    int save(Args args); // std:string
    int load(Args args); // std:string
};


#endif //LIFE_COMMANDO_H
