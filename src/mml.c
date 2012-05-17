#include "human.h"


static __attribute__((constructor)) void _init(void)
{
	randomize();
}
