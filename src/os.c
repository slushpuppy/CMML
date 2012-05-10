#include "os.h"

#include <stdio.h>
#include <stdlib.h>

#ifdef LINUX
Display *display;
#endif

void os_init(void)
{
#ifdef LINUX
	display = XOpenDisplay(NULL);
	if (display == NULL) {
		fprintf(stderr, "Cannot open display!]n");
		exit(1);
	}

	XSelectInput(display, DefaultRootWindow(display), KeyReleaseMask);
#endif
}

void os_free(void)
{
#ifdef LINUX 
	XCloseDisplay(display);
#endif
}
