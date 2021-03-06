#include "ls.h"

/**
 * allocBuf - allocates memory for a buffer
 * @dest: destine
 * @path: pointer
 * @name: pointer
 * @com: char comparision
 *
 * Return: pointer to char
 */
char *allocBuf(char *dest, char *path, char *name, char *com)
{
	int len = 0;

	if (com != NULL)
		len = 1 + _strlen(com) + _strlen(path) + _strlen(name);
	else
		len = 1 + _strlen(path) + _strlen(name);
	dest = (char *) malloc(len * sizeof(char));
	if (!dest)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	dest = _strcpy(dest, path);
	if (com != NULL)
		dest = _strcat(dest, com);
	dest = _strcat(dest, name);

	return (dest);
}

/**
 * path_controller - controller path
 * @path: path of file / dir
 * @name: char name
 *
 * Return: pointer to char
 */
char *path_controller(char *path, char *name)
{
	char *pc = "../", *buff = NULL;

	if (_strstr(path, pc) != NULL)
		buff = allocBuf(buff, path, name, NULL);
	else
		buff = allocBuf(buff, path, name, "/");

	return (buff);
}
