#include "human.h"

void wait(uint32_t ms)
{
	usleep(ms * 1000);
}

uint32_t mrandom(uint32_t r)
{
	return rand() % r;
}

void mouseMoveH(uint32_t x, uint32_t y)
{
	//windMouse? or?
}

void mouseClickH(mouseButton button)
{
	mouseDown(button);
	wait(80 + mrandom(120));
	mouseUp(button);
	wait(50 + mrandom(50));
}
