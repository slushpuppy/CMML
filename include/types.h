#ifndef __types_h_
#define __types_h_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint32_t x;
	uint32_t y;
} Point;

typedef struct {
	uint32_t x1;
	uint32_t y1;
	uint32_t x2;
	uint32_t y2;
} Box;

typedef enum { mouseLeft, mouseRight, mouseMiddle } mouseButton;
typedef enum { keyUnknown } keyboardKey;

typedef uint32_t Color;

typedef struct {
	uint8_t B;
	uint8_t G;
	uint8_t R;
} RGB28;

typedef struct {
	uint8_t B;
	uint8_t G;
	uint8_t R;
	uint8_t A;
} RGB32;

typedef struct {
	double H;
	double S;
	double L;
} HSL;

extern Point point(uint32_t x, uint32_t y);
extern Box box(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);

#endif
