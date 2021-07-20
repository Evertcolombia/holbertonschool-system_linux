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

	init_flags(&_opts);

	if (argc == 1)
		create_dir_list(".", argc, &_opts);
	else if (argc >= 2)
	{
		args_mannage(argv, &_opts);

		if (argc == 2 && _opts.count > 0)
			create_dir_list(".", argc, &_opts);

		else
		{
			for (i = 1; argv[i]; i++)
			{
				if (argv[i][0] == '-')
					continue;
				dirLen = dir_len(argv[i], &_opts);

				if (dirLen == -1)
				{
					code = 2;
					continue;
				}
				create_dir_list(argv[i], argc, &_opts);
			}
		}
	}
	return (code);
}
