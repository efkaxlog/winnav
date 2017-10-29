#ifndef WINNAV_H
#define WINNAV_H

#include <windows.h>

const char TOP = 0;
const char BOTTOM = 1;
const char LEFT = 2;
const char RIGHT = 3;
const char TOP_LEFT = 4;
const char TOP_RIGHT = 5;
const char BOT_LEFT = 6;
const char BOT_RIGHT = 7;
const char QUIT = 8;

namespace winnav {
    PSTR getActiveWindowTitle();
    RECT getMonitorWorkRect(HMONITOR monitorHandle);
    void moveWindow(char loc);
    int handleHotkey(char hotkey);
}

#endif /* WINNAV_H */

