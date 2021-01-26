//
// Created by МаксиМ on 25.01.2021.
//

#ifndef SPACEPROG_MAP_H
#define SPACEPROG_MAP_H
#include <vector>

class Map {
private:
    int len;
    int height;
    std::vector<std::vector<char>> map;
public:
    int getLen();
    int getHeight();
    std::vector<std::vector<char>> getMap();
    void prolong(char side);
    Map(int l, int h);
    void set(int x, int y, char a);
};


#endif //SPACEPROG_MAP_H
