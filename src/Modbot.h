//
// Created by Michal on 23. 10. 2023.
//

#ifndef COMMS_H_MODBOT_H
#define COMMS_H_MODBOT_H

#include <vector>
#include "arduino.h"
#include "Module.h"
#include "Comms.h"
#include <servo.h>
#include "Joint.h"
#include "Claw.h"
#include "BatteryControl.h"
#include "Mp3Player.h"
#include "Button.h"
#include "USSensor.h"
#include "Wheel.h"
#include "Arm.h"

class Modbot {
public:
    //TODO
    // bulk module setup
    Modbot();
    String listModules(int type = 0);
    module getModule(int index);
    //TODO
    // module getModuleByName(String name);
    void setModule(module mod);
    
protected:
    std::vector<Module> _modules = {};
    std::vector<Servo> _servos = {};
    //TODO
    // std::vector<Servo> setup
    // std::vector<Servo> play

    Comms _comms;
    BatteryControl _bat;
};

#endif //COMMS_H_MODBOT_H
