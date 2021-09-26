#include "signals.h"

void (*current_handler_signal(void))(int);
{
	sighandler_t handler_pointer;

	handler_pointer = signal(SIGINT, SIG_IGN);

	if (handler_pointer == SIG_ERR)
		return (NULL);

	if (signal(SIGINT, handler_pointer) == SIG_ERR)
		return (NULL);
	
	return (handler_pointer);
}
