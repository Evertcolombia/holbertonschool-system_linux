#include "signals.h"

int main(int argc, char *argv[])
{
	int signum = 0;

	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	signum = atoi(argv[1]);
	printf("%d: %s\n", signum, strsignal(signum));
	return (0);
}
