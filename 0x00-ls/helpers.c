#include "ls.h"

/**
 *
 *
 *
 */
void init_flags(_flags *_opts)
{
	_opts->f1 = 0;
	_opts->count = 0;
}

/**
 * arv_mannager - mannage argv flags
 * @arv: char to pointer array
 * @ar_opts: struct to save flags
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
				p++;
			}
		}
	}
}
