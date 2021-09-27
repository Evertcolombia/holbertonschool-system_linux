#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("PID: %d\n", (int)pid);
    while (98)
    {
        printf("Waiting ...\n");
        sleep(1);
    }
    return (EXIT_SUCCESS);
}
