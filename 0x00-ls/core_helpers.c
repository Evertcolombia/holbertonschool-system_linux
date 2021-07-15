#include "ls.h"
/**
 * dont_get_flags - mannage the control for no flags
 * @name: name of the file / dir
 * @path: path file /dir
 * @list: linked list controller
 *
 * Return: int
 */

int dont_get_flags(char *name, char *path, ls_c *list)
{
	char *buff = NULL;

	if (pass_hidden(name) == 0)
		return (0);
	
	/* path is root "." */
	else if (_strcmp(path, ".") == 0)
		statinfo(path, name, list, false);
	else
	{
		buff = path_controller(path, name);
		statinfo(buff, name, list, true);
	}
	return (0);
}

/**
 * pass_hidden - pass hidden files / dir
 * @name: name of the file / dir
 *
 * Return: int
 */
int pass_hidden(char *name)
{
	if (_strcmp(name, ".") == 0 || _strcmp(name, "..") == 0)
		return (0);
	else if (_strncmp(name, ".", 1) == 0)
		return (0);
	return (1);
}
