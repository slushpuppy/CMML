#include "os.h"

#include <stdio.h>
#include <stdlib.h>

Display *display;

static void constructor(101) _init(void)
{
	display = XOpenDisplay(NULL);

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
}

static void destructor(101) _free(void)
{
	XCloseDisplay(display);
}
