
#include "Map.h"

int Map::getLen() { return len;}
int Map::getHeight(){ return height;}
std::vector<std::vector<char>> Map::getMap(){ return map;}
Map::Map(int l, int h){
    len = l;
    height = h;
    for (int i = 0; i<len; ++i){
        map.emplace_back(std::vector<char>(height, 'E'));
    }

}
void Map::prolong(char side) {
    switch (side){
        case 'U':
            height++;
            for (int i = 0; i < len; ++i) {
                map[i].emplace_back('U');
                for(int j = 1; j<height; ++j){
                    map[i][j] = map[i][j-1];
                }
                map[i][0] = 'U';
            }
            //return 1;
            break;
        case 'D':
            height++;
            for (int i = 0; i < len; ++i) {
                map[i].emplace_back('U');
            }
            break;
        case 'L':
            len++;
            map.emplace_back(std::vector<char>(height, 'U'));
            for(int i = 1; i<len; ++i){
                for(int j = 0; j<height; j++) map[i][j] = map[i-1][j];
            }
            for(int j = 0; j<height; j++) map[0][j] = 'U';
            break;
        case 'R':
            len++;
            map.emplace_back(std::vector<char>(height, 'U'));
            break;
        default:
            break;
    }
}
void Map::set(int x, int y, char a){
    map[x][y] = a;
}