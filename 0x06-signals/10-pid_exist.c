#include "signals.h"

int pid_exist(pid_t pid)
{
	return (kill(pid, 0) ? 0 : 1);
}
