#ifndef __os_h_
#define __os_h_

#ifndef LINUX
#ifndef WINDOWS
#define LINUX
#endif
#endif

#include "mml.h"

#ifdef LINUX 

#include <X11/Xlib.h>
#include <X11/Xutil.h>

extern Display *display;

#endif

extern void os_init(void);
extern void os_free(void);

#endif
