//
// Created by МаксиМ on 20.11.2020.
//
#include <vector>
#include "GameField.h"

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