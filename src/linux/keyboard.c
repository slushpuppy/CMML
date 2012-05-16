#include "keyboard.h"
#include <string.h>

static void _SendEvent(keyboardKey key, int type, int32_t mask)
{
	XEvent event;
	memset(&event, 0, sizeof(event));

	event.xkey.type = type;

	event.xkey.display = display;
	XGetInputFocus(display, &event.xkey.window, NULL);
	event.xkey.root = DefaultRootWindow(display);

	event.xkey.x = 1;
	event.xkey.y = 1;
	event.xkey.x_root = 1;
	event.xkey.y_root = 1;

	event.xkey.same_screen = true;

	event.xkey.keycode = key;

	XSendInput(display, InputFocus, True, mask, &event);
}

void keyboardDown(keyboardKey key)
{
	_SendEvent(key, KeyPress, KeyPressMask);
}

void keyboardUp(keyboardKey key)
{
	_SendEvent(key, KeyRelease, KeyReleaseMask);
}

keyboardKey keyboardToKey(const char c)
{
	char s[2] = {c, 0};
	KeySym key = XStringToKeySym(s);
	if (key == NoSymbol) return 0;

	KeyCode code = XKeysymToKeycode(display, key);
	if (code == 0) return 0;

	return code;
}
