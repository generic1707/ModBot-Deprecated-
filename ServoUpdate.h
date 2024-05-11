//
// Created by Michal on 3. 4. 2024.
//

#ifndef COMMS_H_SERVOUPDATE_H
#define COMMS_H_SERVOUPDATE_H

#include "arduino.h"
#include "Joint.h"

class ServoUpdate{
public:
    ServoUpdate(Joint& joint, int speed, int dest);
    Joint* joint;
    int dest;
    int _delay;
    int _step;
};

#endif //COMMS_H_SERVOUPDATE_H
