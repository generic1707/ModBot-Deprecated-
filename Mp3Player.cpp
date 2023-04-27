//
// Created by misko on 27. 4. 2023.
//

#include "Mp3Player.h"

Mp3Player::Mp3Player(int serialPin, int busyPin, int volume = 8): Module(serialPin, "") {
    _busyPin = busyPin;
    _volume = volume;
}

int Mp3Player::getVolume() {
    return _volume;
}

bool Mp3Player::setVolume(int volume) {
    if (volume < 0 || volume > 30){
        return false;
    }
    _volume = volume;
    return false;
}

bool Mp3Player::isPlaying() {
    return (bool)digitalRead(_busyPin);
}

void Mp3Player::play(int trackNum) {
    //TODO
}

void Mp3Player::stop() {
    //TODO
}

bool Mp3Player::incVol() {
    if (_volume == 30){
        return false;
    }
    _volume++;
    return true;
}

bool Mp3Player::decVol() {
    if (_volume == 0){
        return false;
    }
    _volume--;
    return true;
}
