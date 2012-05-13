#ifndef __os_h_
#define __os_h_

#include "mml.h"

#ifndef _WIN32_WINNT
#ifndef _WIN32_WINNT_WINXP
#define _WIN32_WINNT_WINXP 0x0501
#endif

#define _WIN32_WINNT _WIN32_WINNT_WINXP
#endif

#include <windows.h>

#endif
