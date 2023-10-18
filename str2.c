#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break;
		}
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strchr - function
 * @s: string
 * @c: char
 * Return: pointer, or NULL if char not found
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
