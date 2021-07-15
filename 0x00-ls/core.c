#include "ls.h"

/**
 * open_directory - list files from a dir path
 * @dirp: DIR strem pointer
 * @path: pointer to pathname
 * @list: linked list controller
 *
 * Return: DIR stream on success
 */
DIR *open_directory(DIR *dirp, char *path)
{
	dirp  = opendir(path);
	if (dirp == NULL)
	{
		error_mannager(errno, true, path);
	}

	return (dirp);
}


/**
 *  - list files from a dir path
 * @dirpath: pointer to pathname
 * @arc: int
 * @ar_opts: flag structs
 *
 * Return: None
 */
void create_dir_list(const char *path, int ac)
{
	DIR *dirp = NULL;
	struct dirent *dp;
	char *pathCopy = (char *) path;	
	ls_c list;

	list_init(&list);
	dirp = open_directory(dirp, (char *) path);
	
	if (_strcmp(pathCopy, "..") == 0)
		pathCopy = "../";

	while ((dp = readdir(dirp)))
	{
		dont_get_flags(dp->d_name, (char *) path, &list);
	}
	print_safe(ac, &list, pathCopy);
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
 * @arc: int
 * @list: linked l controller
 * @ncase: int
 * @copy: char pointer
 *
 * Retur: none
 */
void print_safe(int ac, ls_c *list, char *copy)
{
	if (ac > 2)
		fprintf(stdout, "%s:\n", copy);

	print_list_safe(list, list->head);

	if (ac > 2 && list->size > 0)
		fprintf(stdout, "%c", '\n');

	list_destroy(list);
}
