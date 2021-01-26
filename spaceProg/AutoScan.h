//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_AUTOSCAN_H
#define SPACEPROG_AUTOSCAN_H

#include "IMode.h"
#include <vector>
#include "IRobot.h"
#include "Map.h"
typedef std::vector<std::pair<Coords, std::vector<std::pair<Coords, Coords>>>> Path;


class AutoScan :public IMode{
    Map* map;
    IRobot* robot;
    int spawnX;
    int spawnY;
public:
    AutoScan(Map &m, IRobot &r,int &n);
    int N;
    void nextMove();
    void passXY(int x, int y);
    //void changeMode(std::string mode);
    int move(int x, int y, IRobot &r);
    int scan(IRobot &r);
    bool sort(std::vector<Coords> exclude, std::vector<std::pair<Coords, Coords>> roads, Coords prev, Coords goal, std::vector<std::pair<Coords, Coords>> path);
    Path calculate(IRobot &r, std::vector<Coords> pool, std::vector<std::pair<Coords, Coords>> roads);
    void movePath(Coords dest, Path path, IRobot &r);
};


#endif //SPACEPROG_AUTOSCAN_H
