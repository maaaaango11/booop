//
// Created by МаксиМ on 20.11.2020.
//
#include <vector>
#include <iostream>
#include <fstream>
#include "Args.h"
#include "GameField.h"

GameField::GameField(int x, int y) {
    int (GameField::*resetPrt)(Args*) = &GameField::reset;
    int (GameField::*setPrt)(Args*) = &GameField::set;
    int (GameField::*clearPrt)(Args*) = &GameField::clear;
    int (GameField::*stepPrt)(Args*) = &GameField::step;
    int (GameField::*backPrt)(Args*) = &GameField::back;
    int (GameField::*savePrt)(Args*) = &GameField::save;
    int (GameField::*loadPrt)(Args*) = &GameField::load;
    commands.push_back(std::make_pair("reset",resetPrt));
    commands.push_back(std::make_pair("set",setPrt));
    commands.push_back(std::make_pair("clear",clearPrt));
    commands.push_back(std::make_pair("step",stepPrt));
    commands.push_back(std::make_pair("back",backPrt));
    commands.push_back(std::make_pair("save",savePrt));
    commands.push_back(std::make_pair("load",loadPrt));
}

char GameField::out(bool a){
    if(a) return '*';
    return '.';
}
int GameField::neighbourhood(int x, int y){
    int counter = 0;
    if(grid[(x + 1) % len][y].getAlive()) counter++;
    if(grid[x][(y + 1) % height].getAlive()) counter++;
    if(grid[(x + 1) % len][(y + 1) % height].getAlive()) counter++;
    if(grid[(x - 1) % len][y].getAlive()) counter++;
    if(grid[x][(y - 1) % height].getAlive()) counter++;
    if(grid[(x - 1) % len][(y - 1) % height].getAlive()) counter++;
    if(grid[(x + 1) % len][(y - 1) % height].getAlive()) counter++;
    if(grid[(x - 1) % len][(y + 1) % height].getAlive()) counter++;
    return counter;
}

void GameField::changeStatus(std::vector<Cell*> cells){
    for (auto const &element: cells)
        element->setAlive(!element->getAlive());
}

void GameField::nextStep() {
    prevGrid = grid; //чую беду
    turn++;
    std::vector<Cell*> cellsList;
    for(int i = 0;i<len;i++){
        for(int j = 0;i<height;j++){
            int n = neighbourhood(i,j);
            if(((n<2)||(n>3))&&(grid[i][j].getAlive())){cellsList.push_back(&grid[i][j]);} //из-за передачи ссылок
            if((n == 3)&&(!grid[i][j].getAlive())){cellsList.push_back(&grid[i][j]);} //
        }
    }
    changeStatus(cellsList);

}

int GameField::reset(Args* args){ //return?

}

int GameField::set(Args* args){ //return?
    grid[args->numbers[0]][args->numbers[1]].setAlive(true);
}

int GameField::clear(Args* args){
    grid[args->numbers[0]][args->numbers[1]].setAlive(false);
}

int GameField::step(Args* args){ //return?
    if(args->numbers[0] != -1){ //change
        for (int i = 0; i<args->numbers[0]; i++) nextStep();
    } else nextStep();
}

int GameField::back(Args* args){ //return?

}

int GameField::save(Args* args){
    std::ofstream file;
    file.open(args->str);
    //in UI??
}

int GameField::load(Args* args){
    std::ifstream file;
    file.open(args->str);
    //in UI??
    //add reconstruction
}
