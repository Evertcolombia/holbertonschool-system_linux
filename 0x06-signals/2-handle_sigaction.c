#include "signals.h"

void print_gotcha(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

int handle_sigaction(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = print_gotcha;
	return (sigaction(SIGINT, &act, NULL));
}
