
#include "Bomber.h"

void Bomber::scan(char tile) {}
int Bomber::getX() {return x;}
int Bomber::getY() {return y;}
void Bomber::move(int a, int b){
    if(map->getMap()[spawnL+a][spawnH+b] != 'U'){
        x+=a;
        y+=b;
    }
}
void Bomber::grab() {
    map->set(x, y, 'E');
    sendTo->getMap()->set(x, y, 'E');
}
Map* Bomber::getMap() {return map;}
void Bomber::connect(IRobot &r){
    sendTo = &r;
    map = r.getMap();
};
void Bomber::setCoords(int a, int b) {
    x = a;
    y = b;
}