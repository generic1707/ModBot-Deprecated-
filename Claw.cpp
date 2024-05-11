//
// Created by Michal on 10. 4. 2023.
//

#include "Claw.h"

Claw::Claw(int pin):Module(pin) {
    _servo.attach(pin);
}

void Claw::open() {
    _servo.write(60);
}

void Claw::close() {
    _servo.write(90);
}
