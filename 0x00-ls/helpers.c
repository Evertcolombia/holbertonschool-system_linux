#include "ls.h"

/**
 * init_flags - set initial values for the flags struct
 * @_opts: struct of type _flags
 *
 * Return: None
 */
void init_flags(_flags *_opts)
{
	_opts->f1 = 0;
	_opts->fa = 0;
	_opts->fA = 0;
	_opts->count = 0;
}

/**
 * args_mannage - mannage argv flags
 * @arv: char to pointer array
 * @_opts: struct to save flags
 *
 * Return: None
 */
void args_mannage(char *arv[], _flags *_opts)
{
	char *p;
	int i;

	for (i = 0; arv[i]; i++)
	{
		if (arv[i][0] == '-' && arv[i][1] != '\0')
		{
			p = (char *) (arv[i] + 1);
			while (*p)
			{
				if (*p == '1')
					_opts->f1 = 1, _opts->count++;
				else if (*p == 'a')
					_opts->fa = 1, _opts->count++;
				else if (*p == 'A')
					_opts->fA = 1, _opts->count++; 
				p++;
			}
		}
	}
}
