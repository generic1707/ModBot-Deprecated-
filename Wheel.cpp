//
// Created by Michal on 10. 4. 2023.
//

#include "Wheel.h"
#include <Servo.h>

Wheel::Wheel(int pin, int limit):Module(pin) {
    _limit = limit;
}

void Wheel::setup() {
    _servo.attach(_pin);
}

bool Wheel::setSpeed(int speed) {
    if (abs(speed) > _limit){
        return false;
    }
    _servo.write(speed);
    return true;
}

bool Wheel::setLimit(int limit) {
    if (limit > 90 || limit < 0){
        return false;
    }
    _limit = limit;
    return true;
}
