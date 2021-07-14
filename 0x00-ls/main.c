#include "ls.h"

/**
 * main - main function program
 * @argc: integer
 * @argv: array pointers\
 *
 * Return: integer
 */
int main(int argc, char *argv[])
{
	(void) argv;
	if (argc == 1)
		create_dir_list(".", argc);
	return (0);
}
