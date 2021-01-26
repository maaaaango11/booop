
#include "Map.h"
#include "IRobot.h"
#include "IMode.h"
#include <vector>
#include <iostream>
#ifndef SPACEPROG_ENGINE_H
#define SPACEPROG_ENGINE_H


class Engine {
Map* map;
IRobot* robot;
int spawnX;
int spawnY;
//Parser parser;
std::vector<std::pair<std::string, IMode*>> modeList;
IMode* current;
public:
    Engine(IRobot &r, IMode &manual, IMode &scan, IMode &autoGrab);
    void spawn(IRobot* r);
    void run(); //cycle
    void changeMode(std::string mode);
    void move(int x, int y);
    void scan();
    void grab();
};


#endif //SPACEPROG_ENGINE_H
