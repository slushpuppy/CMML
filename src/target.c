#include "target.h"

pid_t Target = -1;

pid_t targetGet(void)
{
	return Target;
}

void targetSet(pid_t target)
{
	Target = target;
}
