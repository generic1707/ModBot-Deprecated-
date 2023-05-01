//
// Created by Michal on 10. 4. 2023.
//

#include "Joint.h"


Joint::Joint(int pin, int defAngle, int limitUp, int limitDown): Module(pin) {
    _angle = defAngle;
    _defAngle = defAngle;
    _limitUp = limitUp;
    _limitDown = limitDown;

    _servo.attach(pin);
    _servo.write(defAngle);
}

bool Joint::rotate(int angle) {
    if (angle > _limitUp || angle < _limitDown){
        return false;
    }
    _servo.write(angle);
    return true;
}

void Joint::setDefAngle(int angle) {
    _defAngle = angle;
}

bool Joint::setLimitDown(int limit) {
    if (limit < 0 || limit > _limitUp){
        return false;
    }
    _limitUp = limit;
    return true;
}

bool Joint::setLimitUp(int limit) {
    if (limit > 180 || limit < _limitDown){
        return false;
    }
    _limitUp = limit;
    return true;
}

int Joint::getAngle() {
    return _angle;
}