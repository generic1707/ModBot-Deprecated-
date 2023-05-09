//
// Created by Michal on 10. 4. 2023.
//

#include "Arduino.h"
#include "Arm.h"
#include "Module.h"
#include "Joint.h"

Arm::Arm(int pin1, int pin2, int pinR, int len1, int len2):Module(0) {
    Joint j1 = Joint(pin1);
    Joint j2 = Joint(pin2);
    Joint r = Joint(pinR);
    _j1 = &j1;
    _j2 = &j2;
    _r = &r;
    _len1 = len1;
    _len2 = len2;
}

Arm::Arm(Joint* j1, Joint* j2, Joint* r, int len1, int len2):Module(0) {
    _j1 = j1;
    _j2 = j2;
    _r = r;
    _len1 = len1;
    _len2 = len2;
}

void Arm::setup() {
    _j1->setup();
    _j2->setup();
    _r->setup();
}

int Arm::rotate(int joint, int angle) {
    if (joint == 1){
        if (!_j1->rotate(angle)){
            return 2;
        }
        return 0;
    }
    if (joint == 2){
        if (!_j2->rotate(angle)){
            return 2;
        }
        return 0;
    }
    return 1;
}

int Arm::moveToXYZ(float x, float y, float z) {

    return -1;
}

