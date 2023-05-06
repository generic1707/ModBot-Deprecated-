//
// Created by misko on 27. 4. 2023.
//

#include  "Arduino.h"
#include "Mp3Player.h"

Mp3Player::Mp3Player(int serialPin, int busyPin, int volume = 8): Module(serialPin) {
    _busyPin = busyPin;
    _volume = volume;
}

int Mp3Player::getVolume() {
    return _volume;
}

bool Mp3Player::setVolume(int volume) {
    if (Serial){
        Serial.println("mp3Player: volume set to "+String(volume));
    }
    if (volume < 0 || volume > 30){
        return false;
    }
    _volume = volume;
    sendPacket(0x06);
    return false;
}

bool Mp3Player::isPlaying() {
    return (bool)digitalRead(_busyPin);
}

void Mp3Player::play(uint8_t trackNum) {
    if (Serial){
        Serial.println("mp3Player: play track num. "+String(trackNum));
    }
    sendPacket(0x03, trackNum);
}

void Mp3Player::stop() {
    if (Serial){
        Serial.println("mp3Player: stopped playback");
    }
    sendPacket(0x0E);
}

bool Mp3Player::incVol() {
    if (_volume == 30){
        return false;
    }
    _volume++;
    sendPacket(0x04);
    return true;
}

bool Mp3Player::decVol() {
    if (_volume == 0){
        return false;
    }
    _volume--;
    sendPacket(0x05);
    return true;
}

void Mp3Player::sendByte(uint8_t val) {
    pinMode(_pin, OUTPUT);
    float start_transmission = micros();
    float one_bit = 1000000 / 9600.0;
    float next_change = start_transmission + one_bit;
    digitalWrite(_pin, LOW);
    while (micros() < next_change);

    for (int i = 2; i < 10; i++)
    {
        if (val & 1) {
            digitalWrite(_pin, HIGH);
        }else {
            digitalWrite(_pin, LOW);
        }
        next_change = start_transmission + one_bit * i;
        val >>= 1;
        while (micros() < next_change);
    }

    digitalWrite(_pin, HIGH);
    next_change = micros() + 2 * one_bit;
    while (micros() < next_change);
    pinMode(_pin, INPUT);
}

void Mp3Player::sendPacket(uint8_t cmd, uint16_t param = -1) {
    Serial.println("packet with cmd: " + String(cmd));
    sendByte(0x7E);
    sendByte(0xFF);
    uint16_t chksm = 0x00;
    if (param < 0){
        sendByte(0x04);
        sendByte(cmd);
        sendByte(0x00);
        chksm = 0xFF + 0x04 + cmd;
    }else{
        sendByte(0x06);
        sendByte(cmd);
        sendByte(0x00);
        sendByte((uint8_t)(param >> 8));
        sendByte((uint8_t)(param & 0xFF));
        chksm = 0xFF + 0x06 + cmd + (param >> 8) + (param & 0xFF);
    }

    chksm = -chksm;
    sendByte((uint8_t)(chksm >> 8));
    sendByte((uint8_t)(chksm & 0xFF));
    sendByte(0xEF);
}
