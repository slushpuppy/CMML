#ifndef TARGETWINDOW_H_INCLUDED
#define TARGETWINDOW_H_INCLUDED

#include <windef.h>

typedef struct {
    HWND handle;
} TargetWindow;

typedef DWORD PID;
TargetWindow window;

#include <targetwindow.h>

#endif // TARGETWINDOW_H_INCLUDED
