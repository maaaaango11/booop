//
// Created by МаксиМ on 25.01.2021.
//

#ifndef SPACEPROG_IMODE_H
#define SPACEPROG_IMODE_H


class IMode {
public:
    virtual void nextMove() = 0;
    virtual ~IMode();
};


#endif //SPACEPROG_IMODE_H
