#include "os.h"

#include <stdio.h>
#include <stdlib.h>

Display *display;

static void __attribute__((constructor(102))) _init(void)
{
	display = XOpenDisplay(NULL);

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
}

static void __attribute__((destructor(102))) _free(void)
{
	XCloseDisplay(display);
}
