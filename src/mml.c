#include "human.h"


static __attribute__((constructor(101))) void _init(void)
{
	randomize();
}
