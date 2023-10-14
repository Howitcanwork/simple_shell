#include "shell.h"

/**
 * *strcpy_f - function
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */
char *strcpy_f(char *dest, char *src)
{
	char *or_dest = dest;

	while ((*dest++ = *src++) != '\0');
	return (or_dest);
}

/**
 * strlen_f - function
 * @s: string
 * Return: integer length of string
 */

int strlen_f(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

/**
 * *strdup_f - function
 * @s: string
 * Return: pointer to dup string
 */

char *strdup_f(const char *s)
{
	size_t len = strdup_f(s);
	char *new_s = (char *)malloc(len + 1);

	if (new_s == NULL)
	{
		return (NULL);
	}

	strdup_f(new_s, s);
	return (new_s);
}
