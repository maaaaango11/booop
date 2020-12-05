//
// Created by МаксиМ on 20.11.2020.
//
#include "Field.h"
#ifndef LIFE_GAMEFIELD_H
#define LIFE_GAMEFIELD_H


class GameField : public Field{
private:
    int turn = 0;
    Cell** prevGrid;
public:
    void nextStep();
    char out(bool a);
    void changeStatus(std::vector<Cell*> cells);
    int neighbourhood(int x, int y);
    GameField(int x, int y) : Field(x, y){};

};


#endif //LIFE_GAMEFIELD_H
