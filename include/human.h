#ifndef __human_h_
#define __human_h_

#include "types.h"

extern void randomize(void);
extern int32_t randRange(int32_t min, int32_t max);
extern int32_t randNumber(int32_t number);

extern void wait(uint32_t ms);
extern void mouseMoveH(uint32_t x, uint32_t y, uint8_t r);
extern void mouseClickH(mouseButton button);

#endif
