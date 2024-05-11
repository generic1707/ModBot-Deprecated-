//
// Created by misko on 27. 4. 2023.
//

#ifndef MODBOT_TOUCH_H
#define MODBOT_TOUCH_H

#include "Arduino.h"
#include "Module.h"

class Button: public Module {
public:
    Button(int pin, bool inverse);
    bool isPressed();
    void invert();
protected:
    bool _inverse;
};


#endif //MODBOT_TOUCH_H
