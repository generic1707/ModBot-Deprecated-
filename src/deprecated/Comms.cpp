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
    String s = Serial.readString();
    s.trim();
    int i = s.indexOf(" ");
    String cmd = "";
    String sArg1 = "";
    String sArg2 = "";
    if (i == -1){
        cmd = s;
    }else{
        if (i != -1){
            cmd = s.substring(0,i);
            cmd.trim();
            s = s.substring(i);
            s.trim();
            i = s.indexOf(" ");
            if (i == -1){
                sArg1 = s;
            } else{
                sArg1 = s.substring(0,i);
                sArg1.trim();
                sArg2 = s.substring(i);
                sArg2.trim();
            }
        }
    }
    //Serial.println(cmd);
    //Serial.println(sArg1);
    //Serial.println(sArg2);
    int cmdI = findCmd(cmd);
    //Serial.println(cmdI);
    if (cmdI == -2){
        serialHelp();
    }
    if (cmdI == -1){
        Serial.println(cmd+" is not a command. 'help' for list of commands.");
    }else{
        int arg = sArg1.toInt();
        //Serial.println("Command type: "+String(_commands[cmdI].type));
        switch (_commands[cmdI].type){
            case 1:
                //Serial.println("type 1");
                _commands[cmdI].cmd1();
                break;
            case 2:
                //Serial.println("type 2");
                _commands[cmdI].cmd2();
                break;
            case 3:
                //Serial.println("type 3");
                _commands[cmdI].cmd3(arg);
                break;
            case 4:
                //Serial.println("type 4");
                _commands[cmdI].cmd4(arg);
                break;
            case 5:
                //Serial.println("type 5");
                float arg2 = sArg1.toFloat();
                float arg3 = sArg2.toFloat();
                _commands[cmdI].cmd5(arg2, arg3);
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
    _commands[_cmdNum] = cmd;
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
    Serial.println("List of commands:");
    for (int i = 0; i < _cmdNum; i++){
        Serial.println(_commands[i].name);
    }
}

int Comms::findCmd(String cmd) {
    if (cmd == "help"){
        return -2;
    }
    for (int i = 0; i < _cmdNum; i++){
        //Serial.println(String(i)+" "+_commands[i].name);
        if (cmd==_commands[i].name){
            return i;
        }
    }
    return -1;
}
