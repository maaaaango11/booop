

#ifndef SPACEPROG_COLLECTOR_H
#define SPACEPROG_COLLECTOR_H
#include "IRobot.h"
#include "Map.h"
class Collector : public IRobot{
Map* map;
int x;
int y;
int spawnL;
int spawnH;
int apples;
public:
    void move(int a, int b);
    void scan(char tile);
    void grab();
    int getX();
    int getY();
};


#endif //SPACEPROG_COLLECTOR_H
