#include "ls.h"
#define PER_DEN "./hls_03: cannot open directory %s: Permission denied\n"
#define NO_EXIST "./hls_03: cannot access %s: No such file or directory\n"

/**
 * dir_len - get numbers of files and dir in a directory
 * @dirName: name path of dir
 *
 * Return: Number of files.
 */
int dir_len(char *dirName, _flags *_opts)
{
	int i = 0;
	DIR *dirObject;
	struct dirent *dp;

	dirObject = open_dir(dirName, _opts);
	if (dirObject == NULL)
		return (-1);

	while ((dp = readdir(dirObject)) != NULL)
	{
		if (dp->d_type == DT_REG)
			i++;
	}
	closedir(dirObject);
	return (i);
}

/**
 * open_dir - open dir and handle errors if happpens
 * @dirName: name of the dir
 *
 * Return: DIR object struct.
 */
DIR *open_dir(char *dirName, _flags *_opts)
{
	DIR *dir = opendir(dirName);
	int errnum;

	if (dir == NULL)
	{
		errnum = errno;
		switch (errnum)
		{
			case 13:
				fprintf(stderr, PER_DEN, dirName);
				return (NULL);
			case 2:
				fprintf(stderr, NO_EXIST, dirName);
				return (NULL);
			case 20:
				_opts->fileCount++;
				stat_file_info(dirName);
				return (NULL);
		}
	}
	return (dir);
}
