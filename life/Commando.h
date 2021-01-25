//
// Created by МаксиМ on 19.11.2020.
//

#ifndef LIFE_COMMANDO_H
#define LIFE_COMMANDO_H


class Commando {
private:
    Args* args = new Args();
    std::string command;
public:
    int getStr();
    std::string sendCommand();
    Args* sendArgs();
};


#endif //LIFE_COMMANDO_H