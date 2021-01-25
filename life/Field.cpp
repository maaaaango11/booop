//
// Created by МаксиМ on 19.11.2020.
//
#include "Field.h"

void Field::generate(){
    if((len == 0) || (height == 0)) grid = nullptr;
    grid = new Cell*[len];
    for(int i = 0; i<len; i++){
        grid[i] = new Cell[height];
    }
    for(int a = 0; a<len; a++){
        for(int b = 0; b<height; b++){
            grid[a][b].setAlive(false);
        }
    }
}

Field::Field(int x, int y){
    len = x;
    height = y;
    generate();
}

int Field::getLen(){
    return len;
}
int Field::getHeight(){
    return height;
}
Cell** Field::getGrid(){
    return grid;
}