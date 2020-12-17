<<<<<<< HEAD
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
    //int neighbourhood(int x, int y);
    //void changeStatus(std::vector<Cell*> cells, bool status); //vector
    int getLen();
    int getHeight();
    //char out(bool a);
    Cell** getGrid();
};

#endif //LIFE_FIELD_H
=======
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
    //int neighbourhood(int x, int y);
    //void changeStatus(std::vector<Cell*> cells, bool status); //vector
    int getLen();
    int getHeight();
    //char out(bool a);
    Cell** getGrid();
};

#endif //LIFE_FIELD_H
>>>>>>> 476c3f8679e3a053f7623a934196f91509dd2542
