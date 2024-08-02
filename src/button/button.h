#pragma once

#include <Arduino.h>

typedef void (*CallbackFunction)();

class Btn {
private:
    bool momentary; // 自复位
    uint8_t  pin;
    bool idleHigh;  // 不触发时pin脚高电平
    int debounceInterval; // milisec
                    
    bool pressed; // 记录是否按下状态
    int pressedPinState; // 如果idleHigh=true, 则这个就是LOW
    unsigned long lastPressedTime;

public:
    Btn(bool momentary, uint8_t pin, bool idleHigh, int debounce);
    void ifPressedDo(CallbackFunction once, CallbackFunction everytime);
    void ifReleasedDo(CallbackFunction once, CallbackFunction everytime);
};