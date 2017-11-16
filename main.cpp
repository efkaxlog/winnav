#include <cstdlib>
#include <windows.h>
#include <string>
#include <iostream>

#include "winnav.h"

/*
 * 
 */
int main(int argc, char** argv) {
	// For now or maybe permanently, default keys for moving windows will be
	// J, I, K, L for top, bottom, left, right, and
	// N, M, comma, full stop, for corners.
    RegisterHotKey(NULL, TOP, MOD_SHIFT | MOD_ALT, 0x49); // I key
    RegisterHotKey(NULL, BOTTOM, MOD_SHIFT | MOD_ALT, 0x4B); // K key
    RegisterHotKey(NULL, LEFT, MOD_SHIFT | MOD_ALT, 0x4A); // J key
	RegisterHotKey(NULL, RIGHT, MOD_SHIFT | MOD_ALT, 0x4C); // L key
	RegisterHotKey(NULL, TOP_LEFT, MOD_SHIFT | MOD_ALT, 0x4E); // N key
	RegisterHotKey(NULL, TOP_RIGHT, MOD_SHIFT | MOD_ALT, 0x4D); // M key
	RegisterHotKey(NULL, BOT_LEFT, MOD_SHIFT | MOD_ALT, 0xBC); // comma key
	RegisterHotKey(NULL, BOT_RIGHT, MOD_SHIFT | MOD_ALT, 0xBE); // full stop key
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

