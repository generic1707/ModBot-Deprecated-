//
// Created by Michal on 3. 4. 2024.
//

#include "ServoUpdates.h"
#include "arduino.h"
#include "Joint.h"
#include <Servo.h>

ServoUpdates::ServoUpdates(int size) {
    _updates.resize(size);
}

void ServoUpdates::addUpdate(Servo *j, int speed, int degree) {
    switch(speed){
        case -3:
            _updates.push_back(Update(j,3,1,map(degree,0,180,500,2500)));
            break;
        case -2:
            _updates.push_back(Update(j,3,2,map(degree,0,180,500,2500)));
            break;
        case -1:
            _updates.push_back(Update(j,2,1,map(degree,0,180,500,2500)));
            break;
        case 0:
            _updates.push_back(Update(j,1,1,map(degree,0,180,500,2500)));
            break;
        case 1:
            _updates.push_back(Update(j,1,2,map(degree,0,180,500,2500)))
            break;
        case 2:
            _updates.push_back(Update(j,1,3,map(degree,0,180,500,2500)));
            break;
        default:
            _updates.push_back(Update(j,1,1,map(degree,0,180,500,2500)));
            break;
    }
}

void ServoUpdates::updateSequen() {
    int time = 0;
    while(!_updates.empty()){
        for(auto const& i : _updates){
            if(time%i.delay==0){
                if(i.dest < i->j.getAngle()){
                    j.
                }
            }
        }
        time++;
    }
}

void ServoUpdates::updateSimult() {

}

