//
// Created by Michal on 10. 4. 2023.
//

#include "Arduino.h"
#include "Module.h"

Module::Module(int pin, String name) {
    _pin = pin;
    _name = name;
}

int Module::getPin() {
    return _pin
}

String Module::getName() {
    return _name
}

void Module::setName(String name) {
    _name = name;
}
