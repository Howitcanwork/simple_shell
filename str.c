#include "shell.h"

/**
 * *_strcpy - function
 * @dest: string
 * @src: string
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = 0;

	return (ptr);
}

/**
 * _strcat - function
 * @dest: destination
 * @src: source
 * Return: concatenated string
 */

char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
	{
		*ptr++ = *src++;
	}
	*ptr = 0;

	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	char *i = s;

	while (*s)
	{
		s++;
	}
	return (s - i);
}

/**
 * _strdup - function
 * @strs: string
 * Return: string
 */

char *_strdup(char *strs)
{
	int p, leng;
	char *co;

	if (!strs)
	{
		return (NULL);
	}
	leng = _strlen(strs);

	co = malloc(sizeof(char) * leng + 1);
	if (!co)
	{
		perror("Malloc failed\n");
		exit(errno);
		free(co);
	}
	for (p = 0; p < leng; p++)
	{
		co[p] = strs[p];
	}
	co[p] = 0;

	return (co);
}
