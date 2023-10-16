#include "shell.h"

/**
 * *_strcpy_f - function
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */
char *_strcpy_f(char *dest, char *src)
{
	size_t s;

	for (s = 0; src[s] != '\0'; s++)
	{
		dest[s] = src[s];
	}
	dest[s] = '\0';

	return (dest);
}

/**
 * strlen_f - function
 * @s: string
 * Return: integer length of string
 */

int _strlen_f(const char *s)
{
	int i;

	for (i = 0; s[i] != 0; i++)
	{
	}

	return (i);
}

/**
 * *strdup_f - function
 * @s: string
 * Return: pointer to dup string
 */

char *_strdup_f(const char *s)
{
	size_t i = _strlen_f(s);
	char *new_s = malloc(sizeof(char) * (i + 1));

	if (new_s == NULL)
	{
		return (NULL);
	}

	_memcpy(new_s, s, i + 1);
	return (new_s);
}
