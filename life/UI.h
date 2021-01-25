//
// Created by МаксиМ on 19.11.2020.
//
#include "GameField.h"
#ifndef LIFE_UI_H
#define LIFE_UI_H
#include <iostream>

class UI {
public:
    void draw(const GameField& field, FILE* file);
    void draw(const GameField& field);
    Cell** fileRead(FILE* file);
};


#endif //LIFE_UI_H
