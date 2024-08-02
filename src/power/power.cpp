#include "power.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include <esp_sleep.h>

PowerManager::PowerManager(U8G2& display) : screenOn(true), 
                                needRefreshScreen(true),
                                lastActivityTime(0), 
                                sleepTimeout(10000), // 10 seconds in milliseconds
                                u8g2(display)
{} 

PowerManager::PowerManager(U8G2& display, unsigned long timeout) : screenOn(true), 
                                needRefreshScreen(true),
                                lastActivityTime(0), 
                                sleepTimeout(timeout), 
                                u8g2(display)
{} 

void PowerManager::updateActivityTime() {
    lastActivityTime = millis();
}

bool PowerManager::shouldEnterSleep() {
    return screenOn && !needRefreshScreen && (millis() - lastActivityTime > sleepTimeout);
}

bool PowerManager::shouldRefresh() {
    return needRefreshScreen;
}

void PowerManager::enterSleep() {
    screenOn = false;
    u8g2.setPowerSave(1);
    needRefreshScreen = false;
}

void PowerManager::wakeUp() {
    if (screenOn == false) {
        screenOn = true;
        updateActivityTime();
        needRefreshScreen = true;
        u8g2.setPowerSave(0);
    }
}

void PowerManager::postDrawing() {
    needRefreshScreen = false;
    updateActivityTime();
}

void PowerManager::refresh() {
    needRefreshScreen = true;
}
