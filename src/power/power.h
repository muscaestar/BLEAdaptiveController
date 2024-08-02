#pragma once

#include <U8g2lib.h>

class PowerManager {
private:
    bool screenOn;
    bool needRefreshScreen;
    unsigned long lastActivityTime;
    unsigned long sleepTimeout; 
    U8G2& u8g2;

public:
    PowerManager(U8G2& display);
    PowerManager(U8G2& display, unsigned long sleepTimeout);
    void updateActivityTime();
    bool shouldEnterSleep();
    bool shouldRefresh();
    void enterSleep();
    void wakeUp();
    void postDrawing();
    void refresh();
};

