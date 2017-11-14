#include <cstdlib>
#include <windows.h>
#include <string>
#include <iostream>

#include "winnav.h"

/*
 * 
 */
int main(int argc, char** argv) {
<<<<<<< HEAD
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
=======
    RegisterHotKey(NULL, TOP, MOD_SHIFT | MOD_ALT, VK_UP);
    RegisterHotKey(NULL, BOTTOM, MOD_SHIFT | MOD_ALT, VK_DOWN);
    RegisterHotKey(NULL, LEFT, MOD_SHIFT | MOD_ALT, VK_LEFT);
    RegisterHotKey(NULL, RIGHT, MOD_SHIFT | MOD_ALT, VK_RIGHT);
    RegisterHotKey(NULL, TOP_LEFT, MOD_SHIFT | MOD_ALT, 0x49); // I
    RegisterHotKey(NULL, BOT_LEFT, MOD_SHIFT | MOD_ALT, 0x4B); // K
    RegisterHotKey(NULL, TOP_RIGHT, MOD_SHIFT | MOD_ALT, 0x4F); // O
    RegisterHotKey(NULL, BOT_RIGHT, MOD_SHIFT | MOD_ALT, 0x4C); // L
>>>>>>> d32421bd8dde1964055632dff0be398d249b50be
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

