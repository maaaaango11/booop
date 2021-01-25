//
// Created by МаксиМ on 19.11.2020.
//
#include <iostream>
#include "Args.h"
#include "Commando.h"

Args* Commando::readStrRetArgs() {
    std::string commandRaw;
    std::cin >> commandRaw;
    if(commandRaw.length() != 0){
        args->command = commandRaw.erase((commandRaw.find(' '), commandRaw.length()));
        commandRaw = commandRaw.erase(0, commandRaw.find(' '));
        std::string paramsFirst = commandRaw.erase((commandRaw.find(' '), commandRaw.length()));
        commandRaw = commandRaw.erase(0, commandRaw.find(' '));
        args->numbers[0] = std::stoi(paramsFirst); //what if not int?
        if (commandRaw.length() != 0){ //catch exceptions
            args->numbers[1] = std::stoi(commandRaw);
        } else args->str = paramsFirst;
        return args;
    }
    return nullptr;
}


Args* Commando::getArgs(){
    return readStrRetArgs();
}
Commando::~Commando(){
    delete(args);
}