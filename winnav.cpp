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
	std::cout << "============\nMonitor Work Rect: \n";
	std::cout << "x: " << monitorRect.left << std::endl;
	std::cout << "y: " << monitorRect.top << std::endl;
	std::cout << "right: " << monitorRect.right << std::endl;
	std::cout << "bottom: " << monitorRect.bottom << std::endl;

    // new window coordinates
    int x = monitorRect.left;
    int y = monitorRect.top;
	int width = monitorRect.right - x;
	int height = monitorRect.bottom;
    int halfRight = width / 2;
    int halfBottom = height / 2;

	switch (loc) {
	case TOP:
		height = halfBottom;
		break;
	case BOTTOM:
		y = halfBottom;
		height = halfBottom;
		break;
	case LEFT:
		width = halfRight;
		break;
	case RIGHT:
		x += halfRight;
		width = halfRight;
		break;
	default:
		width = halfRight;
		height = halfBottom;
		if (loc == TOP_RIGHT) {
			x += halfRight;
		} else if (loc == BOT_LEFT) {
			y = halfBottom;
		}
		else if (loc == BOT_RIGHT) {
			x += halfRight;
			y = halfBottom;
		}
		break;
	}

	std::cout << "--------------\nMoving to: \n";
	std::cout << "x: " << x << std::endl;
	std::cout << "y: " << y << std::endl;
	std::cout << "width: " << width << std::endl;
	std::cout << "height: " << height << std::endl;
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
