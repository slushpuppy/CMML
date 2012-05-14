#include "os.h"

#include <stdio.h>
#include <stdlib.h>

Display *display;

static void constructor(102) _init(void)
{
	display = XOpenDisplay(NULL);

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
}

static void destructor(102) _free(void)
{
	XCloseDisplay(display);
}
