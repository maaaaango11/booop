
#ifndef SPACEPROG_MANUAL_H
#define SPACEPROG_MANUAL_H

#include "IMode.h"
#include "Parser.h"
#include "IComm.h"
#include <vector>
#include "IRobot.h"
#include "Map.h"

class Manual : public IMode{
private:
    Map* map;
    IRobot* robot;
    int spawnX;
    int spawnY;
   std::vector<std::pair<std::string, int(Manual::*)(IRobot&,Args*)>> commands;//int(Engine::*)(Args*)
    Parser parser;
    bool doChangeMode;
    std::string nextMode;
public:
    Manual(Parser& p, Map &m, IRobot &r, bool &change, std::string &next);
    void nextMove();
    void passXY(int x, int y);
    int move(IRobot &r, Args* args);
    int scan(IRobot &r, Args* args);
    int grab(IRobot &r, Args* args);
    int changeMode(IRobot &r, Args* args);
    int bomberSwitch(IRobot &r, Args* args);
};


#endif //SPACEPROG_MANUAL_H
