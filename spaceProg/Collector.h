

#ifndef SPACEPROG_COLLECTOR_H
#define SPACEPROG_COLLECTOR_H
#include "IRobot.h"
class Collector : public IRobot{
Map* map = new Map(1, 1);
int x = 0;
int y = 0;
int spawnL;
int spawnH;
int apples;
public:
    void move(int a, int b);
    void scan(char tile);
    void grab();
    void setCoords(int a, int b);
    int getX();
    int getY();
    Map* getMap();
    void connect(IRobot &r);
};


#endif //SPACEPROG_COLLECTOR_H
