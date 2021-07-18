#include "ls.h"

/**
 * create_dir_list - create and print a linked list for directory
 * @path: pointer to pathname
 * @ac: int
 *
 * Return: None
 */
void create_dir_list(char *path, int ac)
{
	DIR *dirp = NULL;
	struct dirent *dp;
	char *pathCopy = (char *) path;
	ls_c list;

	if (_strcmp(pathCopy, "..") == 0)
		pathCopy = "../";

	list_init(&list);
	dirp = open_dir(pathCopy);

	while ((dp = readdir(dirp)))
	{
		dont_get_flags(dp->d_name, pathCopy, &list);
	}
	print_safe(ac, &list, path);
	if (closedir(dirp) == -1)
	{
		perror("closedir");
		exit(EXIT_FAILURE);
	}
}


/**
 * statinfo - gets file and dir content
 * @pathname: path to go
 * @name: name of the file /dir
 * @list: linked list controller
 * @isFree: flag
 *
 * Return: int
 */
int statinfo(const char *pathname, char *name, ls_c *list, bool isFree)
{
	struct stat sb;
	if (lstat(pathname, &sb) == -1)
	{
		perror("lstat");
		exit(EXIT_FAILURE);
	}
	list_ins_next(list, list->last_in, name);

	if (isFree)
		free((char *) pathname);
	return(0);
}

/**
 * print_safe - print safe
 * @ac: int
 * @list: linked list controller
 * @copy: char pointer
 *
 * Retur: none
 */
void print_safe(int ac, ls_c *list, char *copy)
{
	if (ac > 2)
		fprintf(stdout, "%s:\n", copy);

	print_list_safe(list, list->head);
	list_destroy(list);
}
