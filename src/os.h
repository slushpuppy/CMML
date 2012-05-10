#ifndef __os_h_
#define __os_h_

#if defined(linux) || defined(__linux) || defined(__linux__)
#define LINUX
#define UNIX
#endif

#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined( __TOS_WIN__) || defined( __WINDOWS__)
#define WINDOWS
#endif

#if defined(macintosh) || defined(Macintosh) || defined(__APPLE__) || defined(__MACH__)
#define MACOSX
#define UNIX
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
