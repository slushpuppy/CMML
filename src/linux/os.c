#include "os.h"

#include <stdio.h>
#include <stdlib.h>

Display *display;

static void __attribute__((constructor)) _init(void)
{
	display = XOpenDisplay(NULL);

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
}

static void __attribute__((destructor)) _free(void)
{
	XCloseDisplay(display);
}
