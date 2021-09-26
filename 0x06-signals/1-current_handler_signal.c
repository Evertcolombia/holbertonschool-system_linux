#include "signals.h"

/**
 * current_handler_signal - returs a pointer to a signal handler
 * @void: void
 *
 * Return: NULL on error, pointer on sucess
 */
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
