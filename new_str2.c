#include "shell.h"

/**
 * strchr_f - function
 * @s: string
 * @c: int
 * Return: pointer
 */

char *strchr_f(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return (char*)s;
		}
		s++;
	}
	return (NULL);
}
