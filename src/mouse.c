#include "mouse.h"

#include <string.h>

void mouseMove(uint32_t x, uint32_t y)
{
#ifdef LINUX
	XWarpPointer(display, None, DefaultRootWindow(display), 0, 0, 0, 0, x, y);
	XFlush(display);
#endif
	
#ifdef WINDOWS
	SetCursorPos(x, y);
#endif
	
#ifdef MACOSX

#endif
}

void mousePos(uint32_t *x, uint32_t *y)
{
#ifdef LINUX
	XEvent event;
	memset(&event, 0, sizeof(event));
	
	XQueryPointer(display, DefaultRootWindow(display),
			&event.xbutton.root, &event.xbutton.window,
			&event.xbutton.x_root, &event.xbutton.y_root,
			&event.xbutton.x, &event.xbutton.y,
			&event.xbutton.state);
	
	*x = event.xbutton.x;
	*y = event.xbutton.y;
#endif
	
#ifdef WINDOWS
	POINT point;
	memset(&point, 0, sizeof(point));

	GetCursorPos(&point);

	*x = point.x;
	*y = point.y;
#endif
	
#ifdef MACOSX
	
#endif
}

#ifdef LINUX
static uint32_t _b2b(mouseButton b)
{
	return b; //FIXME: map mouseButton to X button
}
#endif

#ifdef WINDOWS
static DWORD _b2b(mouseButton b; bool up)
{
	switch (b) {
		case mouseLeft:
			if (up) return MOUSEEVENTF_LEFTUP;
			return MOUSEEVENTF_LEFTDOWN;
			break;
		case mouseRight:
			if (up) return MOUSEEVENTF_RIGHTUP;
			return MOUSEEVENTF_RIGHTDOWN;
			break;
		case mouseMiddle:
			if (up) return MOUSEEVENTF_MIDDLEUP;
			return MOUSEEVENTF_MIDDLEDOWN;
			break;
	}
}
#endif

void mouseClick(mouseButton button)
{
#ifdef LINUX
	XEvent event;
	memset(&event, 0, sizeof(event));
	
	event.xbutton.button = _b2b(button);
	event.xbutton.same_screen = True;
	event.xbutton.subwindow = DefaultRootWindow(display);
	
	while (event.xbutton.subwindow) {
		event.xbutton.window = event.xbutton.subwindow;
		
		XQueryPointer(display, event.xbutton.window,
			&event.xbutton.root, &event.xbutton.subwindow,
			&event.xbutton.x_root, &event.xbutton.y_root,
			&event.xbutton.x, &event.xbutton.y,
			&event.xbutton.state);
	}
	
	event.type = ButtonPress;
	XSendEvent(display, PointerWindow, True, ButtonPressMask, &event);
	XFlush(display);
	
	event.type = ButtonRelease;
	XSendEvent(display, PointerWindow, True, ButtonReleaseMask, &event);
	XFlush(display);
#endif

#ifdef WINDOWS
	INPUT input;
	memset(&input, 0, sizeof(input));
	
	input.type = INPUT_MOUSE;
	
	input.mi.dwFlags = _b2b(button, False);
	SendInput(1, &input, sizeof(input));
	
	input.mi.dwFlags = _b2b(button, True);
	SendInput(1, &input, sizeof(input));
#endif

#ifdef MACOSX

#endif
}

