//
// Created by Michal on 10. 4. 2023.
//

#include "Wheel.h"

Wheel::Wheel(int pin, int limit):Module(pin) {
    _limit = limit;
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
