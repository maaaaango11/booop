

#include "Engine.h"

Engine::Engine(IRobot &r, IMode &manual, IMode &scan, IMode &autoGrab){ //array!
    map = new Map(100, 100);
    robot = &r;
        modeList.emplace_back(std::make_pair("manual", &manual));
        modeList.emplace_back(std::make_pair("scanN", &scan));
        modeList.emplace_back(std::make_pair("auto", &autoGrab));
        current = &manual;
    spawn(robot);
}

void Engine::spawn(IRobot *r) {
    spawnX = rand() % map->getLen();
    spawnY = rand() % map->getHeight();
    run();
}

void Engine::run() {
    //while(1){
    //    current->nextMove();
    //}
}
void Engine::grab() {

    if(map->getMap()[spawnX + robot->getX()][spawnY + robot->getY()] == 'A'){
        map->set(spawnX + robot->getX(), spawnY + robot->getY(), 'E');
        robot->grab();
    }
}
void Engine::changeMode(std::string mode) {
    for(auto &item : modeList){
        if(mode == item.first) current = item.second;
    }
}
void Engine::move(int x, int y) {
    int globalX = spawnX + robot->getX() + x;
    int globalY = spawnY + robot->getY() + y;
    if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)){}
    else {
        if((map->getMap()[globalX][globalY] == 'E') || (map->getMap()[globalX][globalY] == 'A')) robot->move(x,y);
    }
}
void Engine::scan() {
    int no = 0;
    for(int i = -1; i<2; i+=2){
        int globalX = spawnX + robot->getX()+i;
        int globalY = spawnY + robot->getY();
        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
        globalX = spawnX + robot->getX();
        globalY = spawnY + robot->getY()+i;
        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
    }
    int globalX = spawnX + robot->getX();
    int globalY = spawnY + robot->getY();
    if(no == 0){
        robot->scan(map->getMap()[globalX][globalY-1]);
        robot->scan(map->getMap()[globalX-1][globalY]);
        robot->scan(map->getMap()[globalX+1][globalY]);
        robot->scan(map->getMap()[globalX][globalY+1]);
    }
}