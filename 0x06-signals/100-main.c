#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "signals.h"

int main(void)
{
    pid_t pid;

    all_in_one();

    pid = getpid();
    printf("PID: %d\n", (int)pid);
    while (98)
    {
        sleep(2);
    }
    return (EXIT_SUCCESS);
}
