
#ifndef SPACEPROG_ENGINE_H
#define SPACEPROG_ENGINE_H
#include "Map.h"
#include "Manual.h"
#include "AutoScan.h"
#include "AutoGrab.h"
#include "IRobot.h"
#include "IMode.h"
#include "UI.h"
#include "Parser.h"
#include <vector>
#include <iostream>

class Engine {
Map* map;
IRobot* robot;
IRobot* bomber;
int spawnX;
int spawnY;
UI* ui = new UI();
bool bomberMode = false;
bool change = false;
std::string next;
std::vector<std::pair<std::string, IMode*>> modeList;
IMode* current;
public:
    Engine(IRobot &r, IRobot &b);
    void spawn(IRobot* r);
    void run(); //cycle
    void changeMode(std::string mode);
//    int move(int x, int y, IRobot &r);
//    int scan(IRobot &r);
//    int grab(IRobot &r);
    void bomberSwitch();
};


#endif //SPACEPROG_ENGINE_H
