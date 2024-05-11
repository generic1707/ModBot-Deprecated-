//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_WHEEL_H
#define MODBOT_LIBRARY_WHEEL_H

#include "arduino.h"
#include "Module.h"
#include <Servo.h>

class Wheel: public Module{
public:
    Wheel(int pin, int limit = 90);
    void setup();
    bool setSpeed(int speed);
    bool setLimit(int limit);

protected:
    Servo _servo;
    int _limit;
};

#endif //MODBOT_LIBRARY_WHEEL_H
