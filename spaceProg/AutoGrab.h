//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_AUTOGRAB_H
#define SPACEPROG_AUTOGRAB_H

#include "IMode.h"
#include "Parser.h"
#include "IComm.h"
#include <vector>
#include "IRobot.h"
#include "Map.h"

typedef std::vector<std::pair<Coords, std::vector<std::pair<Coords, Coords>>>> Path; // наборы место-путь к нему(в виде набора ребер)

class AutoGrab : public IMode{
private:
    Map* map;
    IRobot* robot;
    IRobot* bomber;
    int spawnX;
    int spawnY;
    bool bomberMode;
public:
    AutoGrab(Map &m, IRobot &r, IRobot &b, bool &mode);
    void nextMove();
    void passXY(int x, int y);
    int move(int x, int y, IRobot &r);
    int grab(IRobot &r);
    bool sort(std::vector<Coords> exclude, std::vector<std::pair<Coords, Coords>> roads, Coords prev, Coords goal, std::vector<std::pair<Coords, Coords>> path);
    Path calculate(IRobot &r, std::vector<Coords> pool, std::vector<std::pair<Coords, Coords>> roads);
    void movePath(Coords dest, Path path, IRobot &r);
};


#endif //SPACEPROG_AUTOGRAB_H
