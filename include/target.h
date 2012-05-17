#ifndef __target_h_
#define __target_h_

#include "types.h"

//TODO: Think out the target interface...
//
// is pid_t portable?
//
// Then add some finding functions to find targets by 
//   size? title? colors (loop thru targets looking for something?)?

extern Target target;

extern Target targetGet(void);
extern void targetSet(Target t);

#endif
