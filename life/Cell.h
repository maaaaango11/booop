//
// Created by МаксиМ on 19.11.2020.
//

#ifndef LIFE_CELL_H
#define LIFE_CELL_H


class Cell{
private:
    //int x, y;
    bool alive = false;
public:
    //Cell(int a, int b);

    bool getAlive();
    void setAlive(bool a);
};
#endif //LIFE_CELL_H