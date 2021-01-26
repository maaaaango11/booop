//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_ARGS_H
#define SPACEPROG_ARGS_H
#include <iostream>

class Args{
private:
    std::string command;
    std::string param1;
    int param2;
public:
    const std::string &getCommand() const {
        return command;
    }

    void setCommand(const std::string &c) {
        Args::command = c;
    }

    const std::string &getParam1() const {
        return param1;
    }

    void setParam1(const std::string &p1) {
        Args::param1 = p1;
    }

    int getParam2() const {
        return param2;
    }

    void setParam2(int p2) {
        Args::param2 = p2;
    }

};
#endif //SPACEPROG_ARGS_H
