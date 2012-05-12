#include "mouse.h"

#include <string.h>

void mouseMove(uint32_t x, uint32_t y)
{
	SetCursorPos(x, y);
}

void mousePos(uint32_t *x, uint32_t *y)
{
	POINT point;
	memset(&point, 0, sizeof(point));

	GetCursorPos(&point);

	*x = point.x;
	*y = point.y;
}

static DWORD _b2b(mouseButton b, int up)
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

void mouseClick(mouseButton button)
{
	INPUT input;
	memset(&input, 0, sizeof(input));
	
	input.type = INPUT_MOUSE;
	
	input.mi.dwFlags = _b2b(button, 1);
	SendInput(1, &input, sizeof(input));
	
	input.mi.dwFlags = _b2b(button, 0);
	SendInput(1, &input, sizeof(input));
}

