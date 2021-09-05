#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - entry to main
 * Desc: main function to print ELF symbol tables
 * @argc: argument count
 * @argv: arguments
 * @env:  environment
 * Return: -1 in fail and 0 in success
 */
int main(int argc, char **argv, char **env)
{
	char *args[] = {"/usr/bin/readelf", "-W", "-s", "", NULL};

	if (argc != 2)
		exit(0);

	args[3] = argv[1];
	if (execve(args[0], args, env) == -1)
	{
		perror("execv");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
