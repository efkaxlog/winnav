#include <iostream>

#include "winnav.h"

PSTR winnav::getActiveWindowTitle() {
    HWND handle = GetForegroundWindow();
    int bufsize = GetWindowTextLength(handle) + 1;
    PSTR pszMem = (PSTR) VirtualAlloc((LPVOID) NULL, 
                    (DWORD) (bufsize), MEM_COMMIT, 
                    PAGE_READWRITE); 
    GetWindowText(handle, pszMem, bufsize);
    return pszMem;
}

RECT winnav::getMonitorWorkRect(HMONITOR monitorHandle) {
    MONITORINFO monitorInfo;
    monitorInfo.cbSize = sizeof(MONITORINFO);
    GetMonitorInfo(monitorHandle, &monitorInfo);
    return monitorInfo.rcWork;
}

void winnav::moveWindow(char loc) {
    HWND handle = GetForegroundWindow();
    HMONITOR monitorHandle = MonitorFromWindow(handle, MONITOR_DEFAULTTONEAREST);
    RECT monitorRect = winnav::getMonitorWorkRect(monitorHandle);
    // new window coordinates
    int x = monitorRect.left;
    int y = monitorRect.top;
    int width, height; 
    int halfRight = monitorRect.right / 2;
    int halfBottom = monitorRect.bottom / 2;
    
    if (loc == TOP || loc == BOTTOM) {
            x = monitorRect.left;
            height = halfBottom;
            width = monitorRect.right;
    } else if (loc == LEFT || loc == RIGHT) {
        y = monitorRect.top;
        height = monitorRect.bottom;
        width = halfRight;
    } else {
        height = halfBottom;
        width = halfRight;
    }
    
    switch(loc) {
        case BOTTOM:
        case BOT_LEFT:
            y = halfBottom;
            break;
        case RIGHT:
        case TOP_RIGHT:
            x = halfRight;
            break;
        case BOT_RIGHT:
            x = halfRight;
            y = halfBottom;
            break;
        default:
            break;
    }
    SetWindowPos(handle, NULL, x, y, width, height, SWP_SHOWWINDOW);
}

int winnav::handleHotkey(char hotkey) {
    if (hotkey == QUIT) {
        std::cout << "Quitting: " << std::endl;
        return 1;
    } else {
        winnav::moveWindow(hotkey);
    }
    return 0;
    
}
