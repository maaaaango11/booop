<<<<<<< HEAD
//
// Created by МаксиМ on 19.11.2020.
//
#include <iostream>
#include "Args.h"
#include "Commando.h"

int Commando::getStr() {
    std::string commandRaw;
    std::cin >> commandRaw;
    if(commandRaw.length() != 0){
        command = commandRaw.erase((commandRaw.find(' '), commandRaw.length()));
        commandRaw = commandRaw.erase(0, commandRaw.find(' '));
        std::string paramsFirst = commandRaw.erase((commandRaw.find(' '), commandRaw.length()));
        commandRaw = commandRaw.erase(0, commandRaw.find(' '));
        args->numbers[0] = std::stoi(paramsFirst); //what if not int?
        if (commandRaw.length() != 0){ //catch exceptions
            args->numbers[1] = std::stoi(commandRaw);
        } else args->str = paramsFirst;
    }
}

std::string Commando::sendCommand(){
    std::string out = command;
    command.clear();
    return out;

}
Args* Commando::sendArgs(){
    return args;
=======
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
>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542
}