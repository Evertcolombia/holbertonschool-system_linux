#ifndef _SIGNALS_H_
#define _SIGNALS_H_


#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int handle_signal(void);
void (*current_handler_signal(void))(int);

#endif /* _SIGNALS_H_ */
