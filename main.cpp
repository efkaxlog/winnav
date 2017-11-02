#include <cstdlib>
#include <windows.h>
#include <string>
#include <iostream>

#include "winnav.h"

/*
 * 
 */
int main(int argc, char** argv) {
    RegisterHotKey(NULL, TOP, MOD_SHIFT | MOD_ALT, VK_UP);
    RegisterHotKey(NULL, BOTTOM, MOD_SHIFT | MOD_ALT, VK_DOWN);
    RegisterHotKey(NULL, LEFT, MOD_SHIFT | MOD_ALT, VK_LEFT);
    RegisterHotKey(NULL, RIGHT, MOD_SHIFT | MOD_ALT, VK_RIGHT);
    RegisterHotKey(NULL, TOP_LEFT, MOD_SHIFT | MOD_ALT, 0x49); // I
    RegisterHotKey(NULL, BOT_LEFT, MOD_SHIFT | MOD_ALT, 0x4B); // K
    RegisterHotKey(NULL, TOP_RIGHT, MOD_SHIFT | MOD_ALT, 0x4F); // O
    RegisterHotKey(NULL, BOT_RIGHT, MOD_SHIFT | MOD_ALT, 0x4C); // L
    RegisterHotKey(NULL, QUIT, MOD_SHIFT | MOD_ALT, 0x51); // Q key
    MSG msg;
    while(GetMessage(&msg, NULL, 0, 0)) {
        char message = msg.wParam;
        if (winnav::handleHotkey(message)) {
            break; // program quit
        }
    }
    // Do clean up here. Maybe unregister hotkeys if it's not done automatically.
    return 0;
}

