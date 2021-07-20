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

	if (pass_hidden(name, true) == 0)
		return (0);
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
 * get_flags - mannage the control for flags
 * @name: char name
 * @path: char path
 * @list: list controller
 * @_opts: flags structure
 *
 * Return: int
 */
int get_flags(char *name, char *path, ls_c *list, _flags *_opts)
{
	char *buff = NULL;

	if (_opts->fA != 0 && _opts->fa == 0)
	{
		if (pass_hidden(name, false) == 0)
			return (0);
	}
	else if (_opts->fa == 0)
	{
		if (pass_hidden(name, true) == 0)
			return (0);
	}
	if (_strcmp(path, ".") == 0)
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
 * @complete: for complete hiden files
 *
 * Return: int
*/
int pass_hidden(char *name, bool complete)
{
	if (_strcmp(name, ".") == 0 || _strcmp(name, "..") == 0)
		return (0);

	if (complete)
	{
		if (_strncmp(name, ".", 1) == 0)
			return (0);
	}
	return (1);
}

/**
 * stat_file_info
 * @path: pathname
 *
 * Return: None
 */
void stat_file_info(char *path)
{
	struct stat sb;
	
	if (lstat(path, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%s\n", path);
}
