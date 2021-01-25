//
// Created by МаксиМ on 20.11.2020.
//
#include "Field.h"
#ifndef LIFE_GAMEFIELD_H
#define LIFE_GAMEFIELD_H

class GameField : public Field{
private:
    int turn = 0;
    int prevTurn = 0;
    std::vector<std::pair<std::string, int(GameField::*)(Args*) >> commands;
    Cell** prevGrid;
    Commando* parser;
public:
    void setParser(Commando* p){
        parser = p;
        nextStep();
    }
    int reset(Args* args); //0
    int set(Args* args); //int x int y
    int clear(Args* args); // int x int y
    int step(Args* args); //0, int n
    int back(Args* args); //0
    int save(Args* args); // std:string
    int load(Args* args); // std:string
    void nextStep();
    void changeStatus(std::vector<Cell*> cells);
    int neighbourhood(int x, int y);
    GameField(int x1, int y1); //: Field(x, y){};
    void waitCommand();
    friend std::ostream& operator<<(std::ostream& out, const GameField& gameField);
    friend std::istream& operator>>(std::istream& in, const GameField& gameField);

};

#endif //LIFE_GAMEFIELD_H