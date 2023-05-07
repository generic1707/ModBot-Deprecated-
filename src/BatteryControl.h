//
// Created by misko on 1. 5. 2023.
//

#ifndef MODBOT_BATTERYCONTROL_H
#define MODBOT_BATTERYCONTROL_H

#include "Arduino.h"
#include "Module.h"

class BatteryControl {
public:
    BatteryControl(int analogPin, float limit);
    float batteryLevel();
    void shutdown();
protected:
    float limit;
};


#endif //MODBOT_BATTERYCONTROL_H
