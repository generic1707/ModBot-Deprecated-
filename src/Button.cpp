//
// Created by misko on 27. 4. 2023.
//

#include  "Arduino.h"
#include "Button.h"

Button::Button(int pin, bool inverse): Module(pin) {
    _inverse = inverse;
    pinMode(pin, INPUT);
}

bool Button::isPressed() {
    if (digitalRead(_pin) == HIGH){
        return !_inverse;
    }
    return _inverse;
}

void Button::invert() {
    _inverse = !_inverse;
}