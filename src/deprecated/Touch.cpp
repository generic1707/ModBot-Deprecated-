//
// Created by misko on 27. 4. 2023.
//

#include  "Arduino.h"
#include "Touch.h"

Touch::Touch(int pin, bool inverse): Module(pin) {
    _inverse = inverse;
    pinMode(pin, INPUT);
}

bool Touch::isTouched() {
    if (digitalRead(_pin) == HIGH){
        return !_inverse;
    }
    return _inverse;
}

void Touch::invert() {
    _inverse = !_inverse;
}