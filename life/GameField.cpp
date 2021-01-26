//
// Created by МаксиМ on 20.11.2020.
//
#include "GameField.h"

std::ostream& operator<<(std::ostream &out, const GameField &gameField) {
    for(int i = 0; i<gameField.len; i++){
        for(int j = 0; j<gameField.height; j++){
            out << (gameField.grid->getGrid()[i][j].getAlive() ? "1" : "0");
        }
        out<<"\n";
    }
    return out;
}

GameField::GameField(int x1, int y1) {
    int (GameField::*resetPrt)(Args*) = &GameField::reset;
    int (GameField::*setPrt)(Args*) = &GameField::set;
    int (GameField::*clearPrt)(Args*) = &GameField::clear;
    int (GameField::*stepPrt)(Args*) = &GameField::step;
    int (GameField::*backPrt)(Args*) = &GameField::back;
    int (GameField::*savePrt)(Args*) = &GameField::save;
    int (GameField::*loadPrt)(Args*) = &GameField::load;
    commands.emplace_back(std::make_pair("reset",resetPrt));
    commands.emplace_back(std::make_pair("set",setPrt));
    commands.emplace_back(std::make_pair("clear",clearPrt));
    commands.emplace_back(std::make_pair("step",stepPrt));
    commands.emplace_back(std::make_pair("back",backPrt));
    commands.emplace_back(std::make_pair("save",savePrt));
    commands.emplace_back(std::make_pair("load",loadPrt));
    grid = new Field(len, height);
    prevGrid = grid;
}

int GameField::neighbourhood(int x, int y){
    int counter = 0;
    if(grid->getGrid()[(x + 1) % len][y].getAlive()) counter++;
    if(grid->getGrid()[x][(y + 1) % height].getAlive()) counter++;
    if(grid->getGrid()[(x + 1) % len][(y + 1) % height].getAlive()) counter++;
    if(grid->getGrid()[((x - 1) % len)<0 ? len+((x - 1) % len) : (x - 1) % len][y].getAlive()) counter++;
    if(grid->getGrid()[x][((y - 1) % height)<0 ? height+((y - 1) % height) : ((y - 1) % height)].getAlive()) counter++;
    if(grid->getGrid()[((x - 1) % len)<0 ? len+((x - 1) % len) : (x - 1) % len][(y - 1) % height].getAlive()) counter++;
    if(grid->getGrid()[(x + 1) % len][((y - 1) % height)<0 ? height+((y - 1) % height) : ((y - 1) % height)].getAlive()) counter++;
    if(grid->getGrid()[((x - 1) % len)<0 ? len+((x - 1) % len) : (x - 1) % len][(y + 1) % height].getAlive()) counter++;
    return counter;
}

void GameField::changeStatus(std::vector<Cell*> cells){
    for (auto const &element: cells)
        element->setAlive(!element->getAlive());
}

void GameField::nextStep() {
    //2 зарезервированных поля на одном(grid) всё меняем по данным сo второго(prevGrid)
    turn++;
    std::vector<Cell*> cellsList;
    for(int i = 0;i<len;i++){
        for(int j = 0;j<height;j++){
            int n = neighbourhood(i,j);
            //if(((n<2)||(n>3))&&(grid[i][j].getAlive())){cellsList.push_back(&grid[i][j]);} //не добавлять в список а сразу менять
            //if((n == 3)&&(!grid[i][j].getAlive())){cellsList.push_back(&grid[i][j]);}
            if(((n<2)||(n>3))&&(grid->getGrid()[i][j].getAlive())){prevGrid->getGrid()[i][j].setAlive(!prevGrid->getGrid()[i][j].getAlive());}
            if((n == 3)&&(!grid->getGrid()[i][j].getAlive())){prevGrid->getGrid()[i][j].setAlive(!prevGrid->getGrid()[i][j].getAlive());}
        }
    }
    back(nullptr);
    //changeStatus(cellsList);
    std::cout<<this<<std::endl; //
    waitCommand();
}

void GameField::waitCommand(){
    Args* args = parser->getArgs();
    if(args != nullptr){
        for(auto const &element : commands){
            if(args->command == element.first){
                (*this.*element.second)(args);
            }
        }
    }
}


int GameField::reset(Args* args){ //return?
    turn = 0;
    prevTurn = 0;
    delete[](prevGrid);
    prevGrid = nullptr;
    delete[](grid);
    grid = nullptr;
    //generate();
}

int GameField::set(Args* args){ //return?
    grid->getGrid()[args->numbers[0]][args->numbers[1]].setAlive(true);
}

int GameField::clear(Args* args){
    grid->getGrid()[args->numbers[0]][args->numbers[1]].setAlive(false);
}

int GameField::step(Args* args){ //return?
    if(args->numbers[0] != -1){ //change
        for (int i = 0; i<args->numbers[0]; i++) nextStep();
    } else nextStep();
}

int GameField::back(Args* args){ //return?
    //int ti = turn;
    //turn = prevTurn;
    //prevTurn = ti;
    Field* tg = grid;
    grid = prevGrid;
    prevGrid = tg;
}

int GameField::save(Args* args){
    if(args->str != ""){
        std::ofstream file;
        file.open(args->str);
        file<<this;
    }
}

int GameField::load(Args* args){
    std::ifstream file;
    file.open(args->str);
    //in UI??
    //add reconstruction
}

