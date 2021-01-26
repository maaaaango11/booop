//
// Created by МаксиМ on 26.01.2021.
//

#ifndef SPACEPROG_COORDS_H
#define SPACEPROG_COORDS_H
class Coords{
public:
    int x;
    int y;
    Coords(int a, int b){
        x = a;
        y = b;
    }
    bool operator==(Coords& c){
        return x == c.x && y == c.y;
    }
};
#endif //SPACEPROG_COORDS_H
