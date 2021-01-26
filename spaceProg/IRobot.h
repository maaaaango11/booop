//
// Created by МаксиМ on 25.01.2021.
//

#ifndef SPACEPROG_IROBOT_H
#define SPACEPROG_IROBOT_H


class IRobot {
public:
    virtual void move(int a, int b) = 0;
    virtual void scan(char tile) = 0;
    virtual void grab() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual ~IRobot(){};
};


#endif //SPACEPROG_IROBOT_H
