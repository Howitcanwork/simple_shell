#include "shell.h"

/**
 * _strchr_f - function
 * @s: string
 * @c: int
 * Return: pointer
 */

char *_strchr_f(char *s, char c)
{
	unsigned int l = 0;

	for (; *(s + l) != '\0'; l++)
	{
		if (*(s + l) == c)
			return (s + l);
	}

	if (*(s + l) == c)
		return (s + l);

	return ('\0');
}

/**
 * _strcmp_f - function
 * @s1: first string
 * @s2: second string
 * Return: 0
 */

int _strcmp_f(char *s1, char *s2)
{
	int l;

	for (l = 0; s1[l] == s2[l] && s1[l]; l++)
	;

	if (s1[l] > s2[l])
		return (1);
	if (s1[l] < s2[l])
		return (-1);
	return (0);
}

/**
 * _strcat_f - function
 * @dest: destination
 * @src: source
 * Return: pointer
 */

char *_strcat_f(char *dest, char *src)
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
