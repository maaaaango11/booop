
#include "Collector.h"

void Collector::move(int a, int b){
    if(map->getMap()[spawnL+a][spawnH+b] != 'U'){
        x+=a;
        y+=b;
    }
}
void Collector::scan(char tile) {
    if(spawnH+y == 0) {
        map->prolong('U');
        spawnH++;
        map->set(spawnL+x, spawnH+y-1, tile);
    }
    if(spawnL+x == 0){
        map->prolong('L');
        spawnH++;
        map->set(spawnL+x-1, spawnH+y, tile);
    }
    if(spawnL+x == map->getLen()-1){
        map->prolong('R');
        map->set(spawnL+x+1, spawnH+y, tile);
    }
    if(spawnH+y == map->getHeight()-1){
        map->prolong('D');
        map->set(spawnL+x, spawnH+y+1, tile);
    }

}

void Collector::grab() {
    apples++;
    map->set(spawnL+x, spawnH+y, 'E');
}
int Collector::getX() {return x;}
int Collector::getY() {return y;}