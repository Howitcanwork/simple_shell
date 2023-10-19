#include "shell.h"

/**
 * _strchr - function
 * @s: string
 * @c: char
 * Return: pointer or NULL if char not found
 */

char *_strchr(char *s, char c)
{
	char z;

	while (true)
	{
		z = *s++;
		if (z == c)
		{
			return (s - 1);
		}
		if (!z)
		{
			return (NULL);
		}
	}
}
