//
// Created by Michal on 10. 4. 2023.
//

#ifndef MODBOT_LIBRARY_COMMS_H
#define MODBOT_LIBRARY_COMMS_H

#include "arduino.h"
#include "Module.h"

class Comms: public Module{
public:
    Comms(int sampleRate, int clocFreq, int maxCommands);
    void serialListen();
    void i2cListen();
    void i2cWrite(int byte);
    void serialWrite(String text);
    void setSampleRate(int sr);
    void setClockFreq(int cf);
    void addCommand(command cmd);

protected:
    command _commands*;
    int _cmdNum;
    int _sampleRate;
    int _clockFreq;

private:
    void growArray();
    int findCmd(String cmd);
    int _maxCommands;
};

struct command {
    String name;
    int type;
    bool (*cmd1)();
    int (*cmd2)();
    bool (*cmd3)(int);
    int (*cmd4)(int);
    bool (*cmd5)(int, int);
};

#endif //MODBOT_LIBRARY_COMMS_H