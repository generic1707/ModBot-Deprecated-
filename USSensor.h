//
// Created by misko on 27. 4. 2023.
//

#ifndef MODBOT_USSENSOR_H
#define MODBOT_USSENSOR_H

#include "Module.h"

class USSensor: public Module {
public:
    USSensor(int pinIn, int pinOut, int echo = 5);
    long sense(int maxDist = 5);
protected:
    int _pinOut;
    int _echo;
private:
    long microsecondsToCentimeters(long microseconds);
};


#endif //MODBOT_USSENSOR_H
