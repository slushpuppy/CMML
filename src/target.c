#include "target.h"

Target target = -1;

Target targetGet(void)
{
	return target;
}

void targetSet(Target t)
{
	target = t;
}
