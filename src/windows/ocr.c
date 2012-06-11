#include <mml.h>
#include <ocr.h>
#include <Wingdi.h>

COLORREF getColorAt(TargetWindow window,int x,int y) {
    HDC hdc;
    COLORREF color;
    hdc = GetDC(window.handle);
    if (!hdc) return CLR_INVALID;
    color = GetPixel(hdc,x,y);
    ReleaseDC(window.handle,hdc);
    return color;
}
