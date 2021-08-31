#include "elfread.h"

/**
 * print_spaces - helpers to print presentation of program
 * @spaces: total spaces to create
 *
 * Return: None
 */
void print_spaces(int spaces)
{
	int i = 0;

	for (; i < spaces; i++)
		printf(" ");
}

/**
 * struct_iterator - iterates over an object 
 * @h_t: header types
 * @size: size of the object
 * @flag: flag to check
 *
 * Return: None
 */
void struct_iterator(Hdr_t *h_t, int size, unsigned char flag)
{
	int i = 0;

	while (i < size)
	{
		if (flag == h_t[i].type)
		{
			printf("%s\n", h_t[i].msg);
			break;
		}
		i++;
	}
}
