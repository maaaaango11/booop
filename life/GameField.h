<<<<<<< HEAD
//
// Created by МаксиМ on 20.11.2020.
//
#include "Field.h"
#ifndef LIFE_GAMEFIELD_H
#define LIFE_GAMEFIELD_H

class GameField : public Field{
private:
    int turn = 0;
    std::vector<std::pair<std::string, int(GameField::*)(Args*) >> commands;
    Cell** prevGrid;
public:
    int reset(Args* args); //0
    int set(Args* args); //int x int y
    int clear(Args* args); // int x int y
    int step(Args* args); //0, int n
    int back(Args* args); //0
    int save(Args* args); // std:string
    int load(Args* args); // std:string
    void nextStep();
    char out(bool a);
    void changeStatus(std::vector<Cell*> cells);
    int neighbourhood(int x, int y);
    GameField(int x, int y) : Field(x, y){};

};


#endif //LIFE_GAMEFIELD_H
=======
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
>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542
