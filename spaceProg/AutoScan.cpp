
#include "AutoScan.h"

void AutoScan::nextMove() {
    for(int i = 0; i<N; i++){
        robot->getMap()->process();
        robot->getMap()->createGraph();
        calculate(*robot,robot->getMap()->getApples(), robot->getMap()->getGraph());
        //movePath();
    }
}
void AutoScan::passXY(int x, int y) {
    spawnX = x;
    spawnY = y;
}

AutoScan::AutoScan(Map &m, IRobot &r, int &n) {
    map = &m;
    robot = &r;
    N = n;
}

int AutoScan::move(int x, int y, IRobot &r) {
    int globalX = spawnX + r.getX() + x;
    int globalY = spawnY + r.getY() + y;
    if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)){}
    else {
        if((map->getMap()[globalX][globalY] == 'E') || (map->getMap()[globalX][globalY] == 'A')) r.move(x,y);
    }
}
int AutoScan::scan(IRobot &r) {
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

bool AutoScan::sort(std::vector<Coords> exclude, std::vector<std::pair<Coords, Coords>> roads, Coords prev, Coords goal, std::vector<std::pair<Coords, Coords>> path){
    bool no = false;
    while(!(prev == goal)){
        for(auto &item : roads){
            if(item.second == prev){
                for(auto &ex : exclude){
                    if(item.first == ex) {
                        no = true;
                        break;
                    }
                }
                if(!no){
                    exclude.emplace_back(prev);
                    if(sort(exclude, roads, item.first, goal, path)){
                        path.emplace_back(std::make_pair(item.first, prev));
                    }
                } else return false;
            }
        }
    }
    return true;
}

Path AutoScan::calculate(IRobot &r, std::vector<Coords> pool, std::vector<std::pair<Coords, Coords>> roads){
    Coords head(r.getX(), r.getY());
    Path collection;
    for(auto &item : pool){
        for(auto &tail : roads){ //find tail
            if(tail.second == item){
                std::vector<Coords> exclude;
                std::vector<std::pair<Coords, Coords>> path;
                if(sort(exclude, roads, item, head, path)) collection.emplace_back(std::make_pair(item, path));
            }
        }
    }
    return collection;
}

void AutoScan::movePath(Coords dest, Path path, IRobot &r){
    while(!(Coords(r.getX(), r.getY()) == dest)){
        for(auto &item : path){
            if(item.first == dest){
                for(int i = 0; i<item.second.size(); i++){
                    int x = 0;
                    int y = 0;
                    if(item.second[i].first.x - item.second[i].second.x == 1) x++;
                    if(item.second[i].first.x - item.second[i].second.x == -1) x--;
                    if(item.second[i].first.y - item.second[i].second.y == -1) y--;
                    if(item.second[i].first.y - item.second[i].second.y == 1) y++;
                    move(x, y, r);
                }
                scan(r);
            }
        }
    }
}
