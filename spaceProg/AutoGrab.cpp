
#include "AutoGrab.h"

void AutoGrab::nextMove() {
    robot->getMap()->process();
    robot->getMap()->createGraph();

    calculate(*robot,robot->getMap()->getApples(), robot->getMap()->getGraph()); //найти все достижимые яблоки

    if(bomberMode){
        bomber->connect(*robot);

        bomber->getMap()->createGraphWBombs();
        calculate(*bomber, bomber->getMap()->getBombs(), bomber->getMap()->getGraphWBombs()); //найти все достижимые бомбы

    }



}
AutoGrab::AutoGrab(Map &m, IRobot &r, IRobot &b, bool &mode) {
    map = &m;
    robot = &r;
    bomber = &b;
    bomberMode = mode;
}
void AutoGrab::passXY(int x, int y) {
    spawnX = x;
    spawnY = y;
}
int AutoGrab::move(int x, int y, IRobot &r) {
    int globalX = spawnX + r.getX() + x;
    int globalY = spawnY + r.getY() + y;
    if((globalX> map->getLen()) ||(globalY> map->getHeight()) || (globalX<0) || (globalY<0)){}
    else {
        if((map->getMap()[globalX][globalY] == 'E') || (map->getMap()[globalX][globalY] == 'A')) r.move(x,y);
    }
}
int AutoGrab::grab(IRobot &r) {
    if(map->getMap()[spawnX + r.getX()][spawnY + r.getY()] == 'A'){
        map->set(spawnX + r.getX(), spawnY + r.getY(), 'E');
        r.grab();
    }
}

bool AutoGrab::sort(std::vector<Coords> exclude, std::vector<std::pair<Coords, Coords>> roads, Coords prev, Coords goal, std::vector<std::pair<Coords, Coords>> path){
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

Path AutoGrab::calculate(IRobot &r,std::vector<Coords> pool, std::vector<std::pair<Coords, Coords>> roads){
    Coords head(r.getX(), r.getY());
    Path collection;
    for(auto &item : pool){
        for(auto &tail : roads){ //find tail
              if(tail.second == item){
                  std::vector<Coords> exclude;
                  std::vector<std::pair<Coords, Coords>> path;
                  if(sort(exclude, roads, item, head, path)) collection.emplace_back(std::make_pair(item, path));
//                std::vector<Coords> exclude;
//                int t = 0;
//                Coords prev = item;
//                while(!(prev == head)){ //пока не найдём путь или его нет
//                    for(auto &road : roads){ //из всех ребер
//                        if(road.second == prev){ // находим пару с интересующей вершиной
//                            for(auto &ex : exclude){
//                                if(!(road.first == ex)){//если другая вершина ребра ещё не пробегалась
//                                    exclude.emplace_back(prev);
//                                    prev = road.first;
//                                } else {
//                                    t++;
//                                    break;
//                                }надо где-нибудь развернуть путь
//                            }
//                        }
//                    }
//                    if(t == 8) break; //если все соседи недоступны
//                }
            }
        }
    }
    return collection;
}

void AutoGrab::movePath(Coords dest, Path path, IRobot &r){
    while(!(Coords(bomber->getX(), bomber->getY()) == dest)){
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
                grab(r);
            }
        }
    }
}