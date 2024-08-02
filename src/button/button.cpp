#include "button.h"
#include <Arduino.h>

Btn:: Btn(bool isMomentary, uint8_t pinNo, bool isIdleHigh, int debounce) : 
    momentary(isMomentary),
    pin(pinNo),
    idleHigh(isIdleHigh),
    debounceInterval(debounce)
{
    pressed = false;
    pressedPinState = idleHigh ? LOW : HIGH;
    lastPressedTime = 0;
}

void Btn::ifPressedDo(CallbackFunction once, CallbackFunction everytime) {
    unsigned long currTime = millis();
    if (currTime - lastPressedTime > debounceInterval) {
        int pinState = digitalRead(pin);
        if (momentary && pinState == pressedPinState) {
            lastPressedTime = currTime;
            if (!pressed) {
                pressed = true;
                once();
            }
            everytime();
        }
        if (!momentary && pinState == pressedPinState) {
            lastPressedTime = currTime;
            pressed = !pressed;
            once();
            everytime();
        }
    }
}

void Btn::ifReleasedDo(CallbackFunction once, CallbackFunction everytime) {
    int pinState = digitalRead(pin);
    if (momentary && pinState != pressedPinState) {
        if (pressed) {
            pressed = false;
            once();
        }
        everytime();
    }
    if (!momentary) {
        // 非自复位的只有按下才有逻辑
    }
}