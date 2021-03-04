
#ifndef SPACEPROG_BOMBER_H
#define SPACEPROG_BOMBER_H

#include "IRobot.h"
#include "Map.h"

class Bomber: public IRobot{
    Map* map = new Map(1, 1);
    IRobot* sendTo;
    int x;
    int y;
    int spawnL;
    int spawnH;
    void move(int a, int b);
    void scan(char tile);
    void setCoords(int a, int b);
    void grab();
    int getX();
    int getY();
    Map* getMap();
    void connect(IRobot &r);
};


#endif //SPACEPROG_BOMBER_H
