//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_JOINT_H
#define MODBOT_LIBRARY_JOINT_H

#include "arduino.h"
#include "Module.h"
#include <Servo.h>

class Joint: public Module{
public:
    Joint(int pin, int defAngle = 90, int limitUp = 180, int limitDown = 0);
    void setup();
    bool rotate(int angle);
    void setDefAngle(int angle);
    bool setLimitUp(int limit);
    bool setLimitDown(int limit);
    int getAngle();

protected:
    Servo _servo;
    int _angle;
    int _defAngle;
    int _limitUp;
    int _limitDown;
};

#endif //MODBOT_LIBRARY_JOINT_H
