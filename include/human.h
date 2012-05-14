#ifndef __human_h_
#define __human_h_

#include "mml.h"

extern void wait(uint32_t ms);
extern uint32_t mrandom(uint32_t r);
extern void mouseMoveH(uint32_t x, uint32_t y);
extern void mouseClickH(mouseButton button);

#define random(x) mrandom(x)

#endif
