
#include "Engine.h"

Engine::Engine(IRobot &r, IRobot &b){ //array!
    map = new Map(10, 10);
    map->addInterest();
    robot = &r;
    bomber = &b;
    Parser parser{};
    Manual manual(parser,  *map, *robot, change, next);
    AutoScan scan(*map, *robot, spawnX);
    AutoGrab autoGrab(*map, *robot, *bomber, bomberMode);
        modeList.emplace_back(std::make_pair("manual", &manual));
        modeList.emplace_back(std::make_pair("scanN", &scan));
        modeList.emplace_back(std::make_pair("auto", &autoGrab));
        current = &manual;
    spawn(robot);
    run();
}

void Engine::spawn(IRobot *r) {
    srand(time(0));
    spawnX = rand() % map->getLen();
    spawnY = rand() % map->getHeight();
    current->passXY(spawnX, spawnY);
    //r->setCoords()
}

void Engine::run() {
    while(true){
        ui->draw(*map, spawnX + robot->getX(), spawnY+ robot->getY());
        current->nextMove();
        if(change) break; //add new ifs to change mode and spawn bomber
    }
    change = false;
    changeMode(next);
}
//int Engine::grab(IRobot &r) {
//
//    if(map->getMap()[spawnX + r.getX()][spawnY + r.getY()] == 'A'){
//        map->set(spawnX + r.getX(), spawnY + r.getY(), 'E');
//        r.grab();
//    }
//}
void Engine::changeMode(std::string mode) {
    for(auto &item : modeList){
        if(mode == item.first) {
            current = item.second;
            run();
        }
    }
}
//int Engine::move(int x, int y, IRobot &r) {
//    int globalX = spawnX + r.getX() + x;
//    int globalY = spawnY + r.getY() + y;
//    if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)){}
//    else {
//        if((map->getMap()[globalX][globalY] == 'E') || (map->getMap()[globalX][globalY] == 'A')) r.move(x,y);
//    }
//}
//int Engine::scan(IRobot &r) {
//    int no = 0;
//    for(int i = -1; i<2; i+=2){
//        int globalX = spawnX + r.getX()+i;
//        int globalY = spawnY + r.getY();
//        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
//        globalX = spawnX + r.getX();
//        globalY = spawnY + r.getY()+i;
//        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
//    }
//    int globalX = spawnX + r.getX();
//    int globalY = spawnY + r.getY();
//    if(no == 0){
//        r.scan(map->getMap()[globalX][globalY-1]);
//        r.scan(map->getMap()[globalX-1][globalY]);
//        r.scan(map->getMap()[globalX+1][globalY]);
//        r.scan(map->getMap()[globalX][globalY+1]);
//    }
//}
void Engine::bomberSwitch() {
    bomberMode = true;
    spawn(bomber);

}