#include "os.h"

#include <stdio.h>
#include <stdlib.h>

Display *display;

static void constructor(101) os_init(void)
{
	display = XOpenDisplay(NULL);

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
}

static void destructor(101) os_free(void)
{
	XCloseDisplay(display);
}
