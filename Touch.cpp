//
// Created by misko on 27. 4. 2023.
//

#include "Touch.h"

Touch::Touch(int pin, bool inverse): Module(pin,"") {
    _inverse = inverse;
}

bool Touch::isTouched() {
    if (digitalRead(_pin) == HIGH){
        return !_inverse
    }
    return _inverse
}

void Touch::invert() {
    _inverse = !_inverse
}