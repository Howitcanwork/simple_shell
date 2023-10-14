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
			return (char *s);
		}
		s++;
	}
	return (NULL);
}

/**
 * strcmp_f - function
 * @s1: first string
 * @s2: second string
 * Return: 0
 */

int strcmp_f(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

/**
 * strcat_f - function
 * @dest: destination
 * @src: source
 * Return: pointer
 */

char *strcat_f(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}
	while (*(src + j) != '\0')
	{
		*(dest + i) = *(src + j);
		i++;
		j++;
	}
	*(dest + i) = *(src + j);

	return (dest);
}
