#ifndef __mouse_h_
#define __mouse_h_

#include "types.h"

extern void mouseMove(uint32_t x, uint32_t y);
extern void mousePos(uint32_t *x, uint32_t *y);

extern void mouseDown(mouseButton button);
extern void mouseUp(mouseButton button);
extern void mouseClick(mouseButton button);

#endif
