#include "ls.h"

/**
 * main - main function program
 * @argc: integer
 * @argv: array pointers
 *
 * Return: integer
 */
int main(int argc, char *argv[])
{
	_flags _opts;
	int i, dirLen, code = 0;

	if (argc == 1)
	{
		dirLen = dir_len(".");
		create_dir_list(".", argc);
	}
	else if (argc >= 2)
	{
		init_flags(&_opts);
		args_mannage(argv, &_opts);

		for (i = 1; argv[i]; i++)
		{
			dirLen = dir_len(argv[i]);
			if (dirLen == -1)
			{
				code = 2;
				continue;
			}
			create_dir_list(argv[i], argc);
		}
	}
	return (code);
}
