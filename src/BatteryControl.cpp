//
// Created by misko on 1. 5. 2023.
//

#include "Arduino.h"
#include "BatteryControl.h"

BatteryControl::BatteryControl(int analogPin, float limit = 620.0):Module(analogPin) {
    _limit = limit;
}

float BatteryControl::batteryLevel() {
    analogReference(INTERNAL);
    float volt = analogRead(_pin);
    analogReference(DEFAULT);
    return volt * 0.01181640625;  // volt * 1.1 * 242 / 22 / 1023  (22 KOhm out of 220+22=242 KOhm)
}

bool BatteryControl::isUnderLimit() {
    if (batteryLevel()*100.0 + 0.5 < _limit){
        return true;
    }
    return false;
}