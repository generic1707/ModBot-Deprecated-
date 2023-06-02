//
// Created by misko on 1. 5. 2023.
//

#ifndef MODBOT_BATTERYCONTROL_H
#define MODBOT_BATTERYCONTROL_H

#include "Arduino.h"
#include "Module.h"

class BatteryControl: public Module {
public:
    BatteryControl(int analogPin, float limit);
    float batteryLevel();
    bool isUnderLimit();
protected:
    float _limit;
};


#endif //MODBOT_BATTERYCONTROL_H
