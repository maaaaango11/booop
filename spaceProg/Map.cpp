
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
    //addInterest();
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
void Map::addInterest() {
    srand(time(0));
    int bombN = rand() %(len*height / 10);
    int appleN = rand()%(len*height / 10);
    for(int i = 0; i<bombN;i++) set(rand()%len,rand()%height, 'B');
    for(int i = 0; i<appleN;i++) set(rand()%len,rand()%height, 'A');
    for(int i = 0; i<height; i++){
        map[0][i] = 'R';
        map[len-1][i] = 'R';
    }
    for(int i = 0; i<len;i++) {
        map[i][0] = 'R';
        map[i][height-1] = 'R';
    }
        //set(rand()%len,rand()%height, 'A');
}
void Map::createGraphWBombs() {
    for(int i = 0; i<len; i++){
        for (int j = 0; j<height; j++){
            if(map[i][j] != 'B' && map[i][j] != 'R'){
                if(map[i+1][j] == 'B' || map[i+1][j] == 'E' || map[i+1][j] == 'A') graphWBombs.emplace_back(std::make_pair(Coords(i,j), Coords(i+1,j)));
                if(map[i-1][j] == 'B' || map[i-1][j] == 'E' || map[i-1][j] == 'A') graphWBombs.emplace_back(std::make_pair(Coords(i,j), Coords(i-1,j)));
                if(map[i][j+1] == 'B' || map[i][j+1] == 'E' || map[i][j+1] == 'A') graphWBombs.emplace_back(std::make_pair(Coords(i,j), Coords(i,j+1)));
                if(map[i][j-1] == 'B' || map[i][j-1] == 'E' || map[i][j-1] == 'A') graphWBombs.emplace_back(std::make_pair(Coords(i,j), Coords(i,j-1)));
            }
        }
    }
}

void Map::process() {
    for(int i = 0; i<len; i++){
        for (int j = 0; j<height; j++){
            if(map[i][j] == 'A') apples.emplace_back(Coords(i,j));
            if(map[i][j] == 'B') bombs.emplace_back(Coords(i,j));
        }
    }
}

void Map::createGraph(){
    for(int i = 0; i<len; i++){
        for (int j = 0; j<height; j++){
            if(map[i][j] != 'R'){
                if(map[i+1][j] == 'E' || map[i+1][j] == 'A') graph.emplace_back(std::make_pair(Coords(i,j), Coords(i+1,j)));
                if(map[i-1][j] == 'E' || map[i-1][j] == 'A') graph.emplace_back(std::make_pair(Coords(i,j), Coords(i-1,j)));
                if(map[i][j+1] == 'E' || map[i][j+1] == 'A') graph.emplace_back(std::make_pair(Coords(i,j), Coords(i,j+1)));
                if(map[i][j-1] == 'E' || map[i][j-1] == 'A') graph.emplace_back(std::make_pair(Coords(i,j), Coords(i,j-1)));
            }
        }
    }
}

std::vector<Coords> Map::getApples() {return apples;}
std::vector<Coords> Map::getBombs() {return bombs;}
std::vector<std::pair<Coords, Coords>> Map::getGraph() { return graph;}
std::vector<std::pair<Coords, Coords>> Map::getGraphWBombs(){ return graphWBombs;}