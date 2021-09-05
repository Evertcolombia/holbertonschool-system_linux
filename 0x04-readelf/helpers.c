#include "elfread.h"

/**
 * print_spaces - helpers to print presentation of program
 * @spaces: total spaces to print
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

/**
 * struct_iterator_2 - helpers to print presentation of program
 * @h_t: total spaces to print
 * @size: size of the object
 * @type: type of the object
 *
 * Return: None
 */
void struct_iterator_2(Hdr_t *h_t, int size, unsigned int type)
{
	int i = 0;

	for (; i < size; i++)
	{
		if (type ==  h_t[i].type)
		{
			printf("%s\n", h_t[i].msg);
			break;
		}
	}
}

/**
 * machine_iterator - helpers to print presentation of program
 * @h_t: total spaces to print
 * @size: size of the object
 * @machine: type of the object
 *
 * Return: Integer
 */
int machine_iterator(Hdr_t *h_t, int size, unsigned int machine)
{
	int i = 0;

	for (; i < size; i++)
	{
		if (machine == h_t[i].type)
		{
			printf("%s\n", h_t[i].msg);
			return (0);
		}
	}
	return (1);

}
