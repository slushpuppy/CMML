#ifndef __target_h_
#define __target_h_

#include "mml.h"

//TODO: Think out the target interface...
//
// is pid_t portable?
//
// Then add some finding functions to find targets by 
//   size? title? colors (loop thru targets looking for something?)?

extern pid_t Target;

extern pid_t targetGet(void);
extern void targetSet(pid_t target);

#endif
