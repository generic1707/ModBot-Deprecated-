//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_MODULES_H
#define MODBOT_LIBRARY_MODULES_H

#include "Arduino.h"

class Module
{
public:
    Module(int pin, int name);
    int getPin();
    int getName();

protected:
    int _pin;
    String _name;
};

#endif //MODBOT_LIBRARY_MODULES_H
