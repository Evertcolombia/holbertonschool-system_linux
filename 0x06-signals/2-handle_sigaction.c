#include "signals.h"

/**
 * print_gotcha - print gotcha
 * @signal: signal
 *
 * Return: None
 */
void print_gotcha(int signal)
{
	printf("Gotcha! [%d]\n", signal);
	fflush(stdout);
}

/**
 * handle_sigaction - hanlde sig action
 * @void: void
 *
 * Return: None
 */
int handle_sigaction(void)
{
	struct sigaction act;

	memset(&act, 0, sizeof(act));
	act.sa_handler = print_gotcha;
	return (sigaction(SIGINT, &act, NULL));
}
