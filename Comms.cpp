//
// Created by Michal on 10. 4. 2023.
//

#include "Arduino.h"
#include "Comms.h"
#include <Wire.h>

Comms::Comms(int sampleRate, int clocFreq, int maxCommands):Module(0) {
    _sampleRate = sampleRate;
    _clockFreq = clocFreq;
    _maxCommands = maxCommands;
    _cmdNum = 0;
    _commands = new command[maxCommands];
}

void Comms::beginSerial() {
    Serial.begin(_sampleRate);
}

void Comms::serialListen() {
    if (!Serial) {
        return;
    }
    while (Serial.available() == 0) {}
    String cmd = Serial.readString();
    Serial.println(cmd);
    int cmdI = findCmd(cmd);
    if (cmdI == -2){
        serialHelp();
    }
    if (cmdI == -1){
        serialWrite(cmd+" is not a command. 'help' for list of commands.");
    }else{
        int arg = 0;
        float arg2 = 0.0;
        float arg3 = 0.0;
        switch (_commands[cmdI].type){
            case 1:
                _commands[cmdI].cmd1();
                break;
            case 2:
                _commands[cmdI].cmd2();
                break;
            case 3:
                
                arg = Serial.parseInt();
                _commands[cmdI].cmd3(arg);
                break;
            case 4:
                arg = Serial.parseInt();
                _commands[cmdI].cmd4(arg);
                break;
            case 5:
                arg2 = Serial.parseFloat();
                arg3 = Serial.parseFloat();
                _commands[cmdI].cmd5(arg, arg2);
                break;
        }
    }
}

void Comms::serialWrite(String text) {
    Serial.println(text);
}

void Comms::i2cListen() {

}

void Comms::i2cWrite(uint8_t byte) {

}

void Comms::setSampleRate(int sr) {
    Serial.end();
    Serial.begin(sr);
    _sampleRate = sr;
}

void Comms::setClockFreq(int cf) {
    Wire.setClock(cf);
    _clockFreq = cf;
}

void Comms::addCommand(command cmd) {
    if (_cmdNum == _maxCommands){
        growArray();
    }
    _commands[_cmdNum + 1] = cmd;
    _cmdNum++;
}

void Comms::growArray() {
    command* newCmd = new command[2*_maxCommands];
    _maxCommands = 2*_maxCommands;
    for (int i = 0; i < _cmdNum; i++){
        newCmd[i] = _commands[i];
    }
    _commands = newCmd;
}

void Comms::serialHelp() {
    for (int i = 0; i < _cmdNum; i++){
        Serial.println(_commands[i].name);
    }
}

int Comms::findCmd(String cmd) {
    cmd.trim();
    if (cmd == "help"){
        return -2;
    }
    for (int i = 0; i < _cmdNum; i++){
        if (cmd.indexOf(_commands[i].name) == 0){
            return i;
        }
    }
    return -1;
}
