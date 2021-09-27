#include "signals.h"

int sigset_init(sigset_t *set, int *signals)
{
	for (sigemptyset(set); *signals != 0; signals++)
		if (sigaddset(set, *signals))
			return (-1);
	return (0);
}
