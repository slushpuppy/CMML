#include <mml.h>
#include <winuser.h>
#include <mouse.h>

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

static DWORD _b2b(mouseButton b, bool up)
{
	switch (b) {
		case mouseLeft: return (up) ? MOUSEEVENTF_LEFTUP:MOUSEEVENTF_LEFTDOWN;
		case mouseRight: return (up) ? MOUSEEVENTF_RIGHTUP:MOUSEEVENTF_RIGHTDOWN;
		case mouseMiddle: return (up) ? MOUSEEVENTF_MIDDLEUP:MOUSEEVENTF_MIDDLEDOWN;
	}
}

void mouseDown(mouseButton button)
{
	INPUT input;
	memset(&input, 0, sizeof(input));

	input.type = INPUT_MOUSE;

	input.mi.dwFlags = _b2b(button, false);
	SendInput(1, &input, sizeof(input));
}

void mouseUp(mouseButton button)
{
	INPUT input;
	memset(&input, 0, sizeof(input));

	input.type = INPUT_MOUSE;

	input.mi.dwFlags = _b2b(button, true);
	SendInput(1, &input, sizeof(input));
}
