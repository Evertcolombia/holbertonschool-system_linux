#include "signals.h"

int main(int argc, char *argv[])
{
	int pid = 0;

	if (argc != 2)
	{
		printf("Usage: %s <pid>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	pid = atoi(argv[1]);
	if (kill(pid, SIGINT) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
