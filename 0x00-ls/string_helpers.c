#include "ls.h"

/**
 * _strlen - show the lenght of a string
 * @s: pointe to  pass the array
 *
 * Return: none
 */
int _strlen(char *s)
{
	char *cp = s;

	while (*cp != '\0')
		cp++;
	return (cp - s);
}

/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: value
 */
int _strcmp(char *s1, char *s2)
{
	for (; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
			return (0);
	}
	return (*s1 - *s2);
}

/**
 * _strncmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * @n: int
 * Return: value
 */
int _strncmp(char *s1, char *s2, int n)
{

	(void) n;

	if (*s1 == '.' && *(s1 + 1) != '.')
	{
		return (0);
	}
	return (*s1 - *s2);
}

/**
 * _strstr - searches string for any set of bytes
 * @haystack: pointer to a string
 * @needle: pointer to a string
 *
 * Return: pointer
 */
char *_strstr(char *haystack, char *needle)
{
	if (needle == '\0')
		return (haystack);

	while (*haystack != '\0')
	{
		if (*haystack == *needle)
			return (haystack);
		haystack++;
	}

	if (*haystack != *needle)
		return (NULL);
	return (0);
}

/**
 * _strcpy - copies the content of a string to other
 * @dest: ponter to save content
 * @src: pointer to copy content
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	char *cp = dest;

	while ((*dest++ = *src++))
		;
	dest = cp;
	return (dest);
}
