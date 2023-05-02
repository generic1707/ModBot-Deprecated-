//
// Created by Michal on 10. 4. 2023.
//

#include "Arduino.h"
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
    while (Serial.available() > 0){
        String cmd = Serial.readStringUntil(" ");
        int cmdI = findCmd(cmd);
        if (cmdI == -1){
            serialWrite(cmd+" is not a command. /help for list of commands.");
            char ch = Serial.read();
            while (ch != '\n'){
                char ch = Serial.read();
            }
        }else{
            switch (_commands[cmdI].type){
                case 1:
                    if (Serial.read() == '\n'){
                        _commands[cmdI].cmd1();
                    }
                    break;
                case 2:
                    if (Serial.read() == '\n'){
                        _commands[cmdI].cmd2();
                    }
                    break;
                case 3:
                    int arg = Serial.parseInt();
                    if (Serial.read() == '\n'){
                        _commands[cmdI].cmd3(arg);
                    }
                    break;
                case 4:
                    int arg = Serial.parseInt();
                    if (Serial.read() == '\n'){
                        _commands[cmdI].cmd4(arg);
                    }
                    break;
                case 5:
                    float arg = Serial.parseFloat();
                    float arg2 = Serial.parseFloat();
                    if (Serial.read() == '\n'){
                        _commands[cmdI].cmd5(arg, arg2);
                    }
                    break;

            }
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
    command newCmd* = new command[2*_maxCommands];
    _maxCommands = 2*_maxCommands;
    for (int i = 0; i < _cmdNum; i++){
        newCmd[i] = _commands[i];
    }
    _commands = &newCmd;
}

int Comms::findCmd(String cmd) {
    for (int i = 0; i < _cmdNum; i++){
        if (cmd == _commands[i].name){
            return i;
        }
    }
    return -1;
}


