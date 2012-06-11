#ifndef __types_h_
#define __types_h_

#include <stdint.h>
#include <stdbool.h>
#include <unistd.h>

#ifdef min
# undef min
#endif
#define min(a,b) ((a)<(b)?(a):(b))

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

typedef struct {
    int x,y;
} TPoint,SIMBA_TPoint;


/* Unpacked records E.g. int example(SIMBA_TPoint * ptr) */

typedef struct {
    char * data;
} SIMBA_string;
/* E.g. int example(SIMBA_string str) */

typedef struct {
    int high;
    union {
        SIMBA_TPoint * atpa;
        int * integer;
        SIMBA_string * string;
    } ;
} SIMBA_Array;
/* E.g. int example(SIMBA_Array array) {
array.atpa
array.integer
array.string
} */
typedef pid_t Target;

#endif
