//
// Created by МаксиМ on 25.01.2021.
//

#ifndef SPACEPROG_MAP_H
#define SPACEPROG_MAP_H
#include <vector>
#include <iostream>
#include <time.h>
#include "Coords.h"

class Map {
private:
    int len;
    int height;
    std::vector<std::vector<char>> map;
    std::vector<Coords> apples;
    std::vector<Coords> bombs;
    std::vector<std::pair<Coords, Coords>> graph;
    std::vector<std::pair<Coords, Coords>> graphWBombs;
public:
    int getLen();
    int getHeight();
    std::vector<std::vector<char>> getMap();
    void prolong(char side);
    Map(int l, int h);
    void set(int x, int y, char a);
    void addInterest();
    void createGraph();
    void createGraphWBombs();
    void process();
    std::vector<Coords> getApples();
    std::vector<Coords> getBombs();
    std::vector<std::pair<Coords, Coords>> getGraph();
    std::vector<std::pair<Coords, Coords>> getGraphWBombs();
};


#endif //SPACEPROG_MAP_H
