
#include "Manual.h"

void Manual::nextMove() {
    Args* args = parser.getArgs();
    for(auto const &item : commands){
        if(args->getCommand() == item.first){
            (*this.*item.second)(*robot, args);
        }
    }
}
Manual::Manual(Parser &p, Map &m, IRobot &r,bool &change, std::string &next) {
    parser = p;
    map = &m;
    robot = &r;
    doChangeMode = change;
    nextMode = next;
    int (Manual::*grabPtr)(IRobot&, Args*) = &Manual::grab;
    int (Manual::*scanPtr)(IRobot&, Args*) = &Manual::scan;
    int (Manual::*movePtr)(IRobot&, Args*) = &Manual::move;
    int (Manual::*changePtr)(IRobot&, Args*) = &Manual::changeMode;
    commands.emplace_back(std::make_pair("move", movePtr));
    commands.emplace_back(std::make_pair("scan", scanPtr));
    commands.emplace_back(std::make_pair("grab", grabPtr));
    commands.emplace_back(std::make_pair("switch_mode", changePtr));
}
void Manual::passXY(int x, int y) {
    spawnX = x;
    spawnY = y;
}
int Manual::grab(IRobot &r, Args* args) {

    if(map->getMap()[spawnX + r.getX()][spawnY + r.getY()] == 'A'){
        map->set(spawnX + r.getX(), spawnY + r.getY(), 'E');
        r.grab();
    }

}

int Manual::move(IRobot &r, Args* args) {
    int x =0, y = 0;
    if(args->getParam1() == "U") y = -1;
    if(args->getParam1() == "D") y = 1;
    if(args->getParam1() == "R") x = 1;
    if(args->getParam1() == "L") x = -1;
    int globalX = spawnX + r.getX() + x;
    int globalY = spawnY + r.getY() + y;
    if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)){}
    else {
        if((map->getMap()[globalX][globalY] == 'E') || (map->getMap()[globalX][globalY] == 'A')) r.move(x,y);
    }

}
int Manual::scan(IRobot &r, Args* args) {
    int no = 0;
    for(int i = -1; i<2; i+=2){
        int globalX = spawnX + r.getX()+i;
        int globalY = spawnY + r.getY();
        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
        globalX = spawnX + r.getX();
        globalY = spawnY + r.getY()+i;
        if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)) no++;
    }
    int globalX = spawnX + r.getX();
    int globalY = spawnY + r.getY();
    if(no == 0){
        r.scan(map->getMap()[globalX][globalY-1]);
        r.scan(map->getMap()[globalX-1][globalY]);
        r.scan(map->getMap()[globalX+1][globalY]);
        r.scan(map->getMap()[globalX][globalY+1]);
    }

}
int Manual::changeMode(IRobot &r, Args *args) {
    doChangeMode = true;
    nextMode = args->getParam1();
}
int Manual::bomberSwitch(IRobot &r, Args* args) {
    //bomberMode = true;
}
