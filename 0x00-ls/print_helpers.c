#include "ls.h"

/**
 * print_list - print list
 * @size: size of the list
 * @head: head of the list
 *
 * Return: int
 */
int print_list(int size, ls_n *head)
{
	int i = 0;

	while (i < size)
	{
		if (i + 1 == size)
			fprintf(stdout, "%s\n", head->name);
		else
			fprintf(stdout, "%s ", head->name);
		head = head->next;
		i++;
	}
	return (i);
}
