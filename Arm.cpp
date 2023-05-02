//
// Created by Michal on 10. 4. 2023.
//

#include "Arduino.h"
#include "Arm.h"

Arm::Arm(int pin1, int pin2, int len1, int len2):Module(0) {
    Joint j1 = Joint(pin1, "bottom");
    Joint j2 = Joint(pin2, "top");
    _j1 = &j1;
    _j2 = &j2;
    _len1 = len1;
    _len2 = len2;
}

Arm::Arm(Joint* j1, Joint* j2, int len1, int len2) {
    _j1 = j1;
    _j2 = j2;
    _len1 = len1;
    _len2 = len2;
}

int Arm::rotate(int j, int angle) {
    if (j == 1){
        if (!_j1->rotate(angle)){
            return 2
        }
        return 0
    }
    if (j == 2){
        if (!_j2->rotate(angle)){
            return 2
        }
        return 0
    }
    return 1
}

int Arm::moveToXZ(float x, float z) {
    while 
}

