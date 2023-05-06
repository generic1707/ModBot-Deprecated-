//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_CLAW_H
#define MODBOT_LIBRARY_CLAW_H

#include "arduino.h"
#include "Module.h"
#include <Servo.h>

class Claw: public Module{
public:
    Claw(int pin);
    void setup();
    void open();
    void close();

protected:
    Servo _servo;
};

#endif //MODBOT_LIBRARY_CLAW_H
