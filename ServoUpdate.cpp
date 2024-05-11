//
// Created by Michal on 3. 4. 2024.
//

#include "ServoUpdate.h"
#include "arduino.h"
#include "Joint.h"

ServoUpdate::ServoUpdate(Joint& joint, int speed, int degree) {
    switch(speed){
        case -3:
            _delay = 3;
            _step = 1;
            break;
        case -2:
            _delay = 3;
            _step = 2;
            break;
        case -1:
            _delay = 2;
            _step = 1;
            break;
        case 0:
            _delay = 1;
            _step = 1;
            break;
        case 1:
            _delay = 1;
            _step = 2;
            break;
        case 2:
            _delay = 1;
            _step = 3;
            break;
        default:
            _delay = 1;
            _step = 1;
            break;
    }
    joint = joint;
    dest = map(degree,0,180,500,2500);
}