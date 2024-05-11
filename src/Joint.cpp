//
// Created by Michal on 10. 4. 2023.
//

#include "Joint.h"


Joint::Joint(int pin, int type, int defAngle, int limitUp, int limitDown): Module(pin, type) {
    _angle = map(defAngle,0,180,500,2500);
    _defAngle = map(defAngle,0,180,500,2500);
    _limitUp = map(limitUp,0,180,500,2500);
    _limitDown = map(limitDown,0,180,500,2500);
}

Joint::Joint():Module(0,0) {
    _angle = 0;
    _defAngle = 0;
    _limitUp = 0;
    _limitDown = 0;
}

void Joint::setup() {
    _servo.attach(_pin);
    _servo.writeMicroseconds(_defAngle);
}

bool Joint::rotate(int angle) {
    if (map(angle,0,180,500,2500) > _limitUp || map(angle,0,180,500,2500) < _limitDown){
        return false;
    }
    _servo.writeMicroseconds(map(angle,0,180,500,2500));
    return true;
}

void Joint::setDefAngle(int angle) {
    _defAngle = map(angle,0,180,500,2500);
}

bool Joint::setLimitDown(int limit) {
    if (map(limit,0,180,500,2500) < 0 || map(limit,0,180,500,2500) > _limitUp){
        return false;
    }
    _limitUp = map(limit,0,180,500,2500);
    return true;
}

bool Joint::setLimitUp(int limit) {
    if (map(limit,0,180,500,2500) > 180 || map(limit,0,180,500,2500) < _limitDown){
        return false;
    }
    _limitUp = map(limit,0,180,500,2500);
    return true;
}

int Joint::getAngle() {
    return map(_angle,500,2500,0,180);
}