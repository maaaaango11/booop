<<<<<<< HEAD
//
// Created by МаксиМ on 19.11.2020.
//
#include "Field.h"

Field::Field(int x, int y){
    len = x;
    height = y;
    grid = new Cell*[x];
    for(int i = 0; i<x; i++){
        grid[i] = new Cell[y];
    }
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
=======
//
// Created by МаксиМ on 19.11.2020.
//
#include "Field.h"

Field::Field(int x, int y){
    len = x;
    height = y;
    grid = new Cell*[x];
    for(int i = 0; i<x; i++){
        grid[i] = new Cell[y];
    }
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
>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542
