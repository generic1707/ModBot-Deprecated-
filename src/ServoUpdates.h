//
// Created by Michal on 3. 4. 2024.
//

#ifndef COMMS_H_SERVOUPDATE_H
#define COMMS_H_SERVOUPDATE_H

#include "arduino.h"
#include <Servo.h>
#include <list>

struct Update{
    Servo* j;
    int delay;
    int step;
    int dest;
};

class ServoUpdates{
public:
    ServoUpdates(int size);
    void addUpdate(Servo* j, int speed, int degree);
    void updateSequen();
    void updateSimult();
protected:
    list<Update> _updates;
};

#endif //COMMS_H_SERVOUPDATE_H
