//
// Created by МаксиМ on 19.11.2020.
//

#include "Commando.h"

Commando::Commando() {
    int (Commando::*resetPrt)(Args) = &Commando::reset;
    int (Commando::*setPrt)(Args) = &Commando::set;
    int (Commando::*clearPrt)(Args) = &Commando::clear;
    int (Commando::*stepPrt)(Args) = &Commando::step;
    int (Commando::*backPrt)(Args) = &Commando::back;
    int (Commando::*savePrt)(Args) = &Commando::save;
    int (Commando::*loadPrt)(Args) = &Commando::load;
    commands.push_back(std::make_pair("reset",resetPrt));
    commands.push_back(std::make_pair("set",setPrt));
    commands.push_back(std::make_pair("clear",clearPrt));
    commands.push_back(std::make_pair("step",stepPrt));
    commands.push_back(std::make_pair("back",backPrt));
    commands.push_back(std::make_pair("save",savePrt));
    commands.push_back(std::make_pair("load",loadPrt));
}

void Commando::getCommand() {
    std::string command;
    std::cin >> command;
    if(command.length() != 0){

    }
}