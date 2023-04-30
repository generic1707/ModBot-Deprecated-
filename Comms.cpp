//
// Created by Michal on 10. 4. 2023.
//

#include "Comms.h"

Comms::Comms(int sampleRate, int clocFreq, int maxCommands):Module(0) {
    _sampleRate = sampleRate;
    _clockFreq = clocFreq;
    _maxCommands = maxCommands;
    _cmdNum = 0;
    command cmd[] = new command[maxCommands];
    _commands = cmd;
}

void Comms::serialListen() {

}

void Comms::serialWrite(int text) {

}

void Comms::i2cListen() {

}

void Comms::serialWrite(int text) {

}

void Comms::setSampleRate() {

}

void Comms::setClockFreq() {

}

void Comms::addCommand(command cmd) {
    if (_cmdNum < )
}
