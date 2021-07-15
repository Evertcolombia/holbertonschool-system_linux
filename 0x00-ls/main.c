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
	_flags _opts;

	if (argc == 1)
		create_dir_list(".", argc);
	else
	{
		init_flags(&_opts);
		args_mannage(argv, &_opts);
		printf("%d\n", _opts.count);
	}
	return (0);
}
