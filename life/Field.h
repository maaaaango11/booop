//
// Created by МаксиМ on 19.11.2020.
//

#ifndef LIFE_FIELD_H
#define LIFE_FIELD_H
#include "Cell.h"

class Field {
protected:
    Cell** grid;
    int len;
    int height;
public:
    Field(int x, int y);
    int getLen();
    int getHeight();
    Cell** getGrid();
    void generate();
};

#endif //LIFE_FIELD_H
