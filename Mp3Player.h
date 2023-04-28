//
// Created by misko on 27. 4. 2023.
//

#ifndef MODBOT_MP3PLAYER_H
#define MODBOT_MP3PLAYER_H

#include "Module.h"

class Mp3Player: public Module {
public:
    Mp3Player(int serialPin, int busyPin, int volume);
    bool setVolume(int volume);
    int getVolume();
    void play(int trackNum);
    void stop();
    bool isPlaying();
    bool incVol();
    bool decVol();
protected:
    int _busyPin;
    int _volume;
    //kód požičaný a upravený z repo https://github.com/Fablab-Slovakia/mokrarosa/blob/master/src/arduino/12_mp3_player/12_mp3_player.ino
    void sendPacket(uint8_t cmd, uint16_t param);
    void sendByte(uint8_t val);
};


#endif //MODBOT_MP3PLAYER_H
