#include "signals.h"

void print_gotcha(int sgnl, siginfo_t *signal_info, void *name)
{
	(void) name;
	(void) sgnl;

	printf("SIGQUIT sent by %d\n", signal_info->si_pid);
}

int trace_signal_sender(void)
{
	struct sigaction action;

	memset(&action, 0, sizeof(action));
	action.sa_sigaction = print_gotcha;
	return (sigaction(SIGQUIT, &action, NULL));
}
