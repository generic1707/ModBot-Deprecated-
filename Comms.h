//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_COMMS_H
#define MODBOT_LIBRARY_COMMS_H

#include "arduino.h"
#include "Module.h"

class Comms: public Module{
public:
    Comms(int sampleRate, int clocFreq);
    void serialListen();
    void i2cListen();
    void i2cWrite(int byte);
    void serialWrite(String text);
    void setSampleRate();
    void setClockFreq();

};

#endif //MODBOT_LIBRARY_COMMS_H
