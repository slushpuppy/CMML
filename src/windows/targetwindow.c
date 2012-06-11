#include <windows.h>
#include <winuser.h>
#include <windows/targetwindow.h>


void setTarget(DWORD pid) {
    DWORD threadId;
    HWND h = GetTopWindow(0);
    while (h) {
        threadId = GetWindowThreadProcessId(h, NULL);
        if (threadId == pid) {
            window.handle = h;
            break;
        }
        h = GetNextWindow( h , GW_HWNDNEXT);
    }
}

