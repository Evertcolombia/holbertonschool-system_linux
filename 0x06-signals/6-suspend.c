#include "signals.h"

void print_gotcha(int sgnl)
{
	printf("Caught %d\n", sgnl);
	printf("Signal received\n");
	fflush(stdout);
}

int main(void)
{
	struct sigaction action;

	memset(&action, 0, sizeof(action));
	action.sa_handler = print_gotcha;
	sigaction(SIGINT, &action, NULL);
	pause();
	return (EXIT_SUCCESS);
}
