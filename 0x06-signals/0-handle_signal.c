#include "signals.h"

void ctrl_c_signal(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}


int handle_signal(void)
{
	if (signal(SIGINT, ctrl_c_signal) == SIG_ERR)
		return (-1);
	return (0);
}
