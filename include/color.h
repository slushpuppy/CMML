#ifndef __color_h_
#define __color_h_

#include "mml.h"

extern Color getPixel(uint32_t x, uint32_t y);

extern Color RGB24ToColor(RGB24 rgb);
extern Color RGB32ToColor(RGB32 rgb);

extern RGB24 ColorToRGB24(Color color);
extern RGB32 ColorToRGB32(Color color);

#endif
