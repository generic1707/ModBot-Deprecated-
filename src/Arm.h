//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_ARM_H
#define MODBOT_LIBRARY_ARM_H

#include "Arduino.h"
#include "Module.h"
#include "Joint.h"

class Arm: public Module{
public:
    Arm(int pin1, int pin2, int pinR, int len1, int len2);
    Arm(Joint* j1, Joint* j2, Joint* r, int len1, int len2);
    void setup();
    int rotate(int joint, int angle);
    int moveToXYZ(float x, float y, float z);

protected:
    Joint* _j1;
    Joint* _j2;
    Joint* _r;
    int _len1;
    int _len2;
};

#endif //MODBOT_LIBRARY_ARM_H
