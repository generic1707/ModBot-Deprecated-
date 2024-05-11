//
// Created by misko on 27. 4. 2023.
//

#ifndef MODBOT_TOUCH_H
#define MODBOT_TOUCH_H

#include "Arduino.h"
#include "Module.h"

class Touch: public Module {
public:
    Touch(int pin, bool inverse);
    bool isTouched();
    void invert();
protected:
    bool _inverse;
};


#endif //MODBOT_TOUCH_H
