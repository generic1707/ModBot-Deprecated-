//
// Created by misko on 27. 4. 2023.
//

#include  "Arduino.h"
#include "USSensor.h"

USSensor::USSensor(int pinIn, int pinOut, int echo): Module(pinIn) {
    _pinOut = pinOut;
    _echo = echo;
    pinMode(_pin, INPUT);
    pinMode(_pinOut, OUTPUT);
}

long USSensor::sense(int maxDist) {
    long duration;
    digitalWrite(_pinOut, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinOut, HIGH);
    delayMicroseconds(5);
    digitalWrite(_pinOut, LOW);
    duration = pulseIn(_pin, HIGH, maxDist*58+10);
    return microsecondsToCentimeters(duration);
}

long USSensor::microsecondsToCentimeters(long microseconds) {
    // The speed of sound is 340 m/s or 29 microseconds per centimeter.
    // The ping travels out and back, so to find the distance of the object we
    // take half of the distance travelled.
    return microseconds / 29 / 2;
}
