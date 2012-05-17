#ifndef __types_h_
#define __types_h_

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#ifdef min
# undef min
#endif
#define min(a,b) ((a)<(b)?(a):(b))

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

typedef uint32_t Color;

typedef struct {
	uint8_t B;
	uint8_t G;
	uint8_t R;
} RGB24;

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

typedef pid_t Target;

#endif
