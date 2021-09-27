#include "signals.h"

void (*current_handler_sigaction(void))(int)
{
	struct sigaction old_signal;

	memset(&old_signal, 0, sizeof(old_signal));
	if (!sigaction(SIGINT, NULL, &old_signal))
		return (old_signal.sa_handler);
	return (NULL);
}
