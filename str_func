#include "shell.h"
#include  <string.h>


/**
 * my_strlen - length of string
 * @st: string
 * Return: int of string length
 */

int my_strlen(char *st)
{
	int i = 0;

	if (!st)
		return (0);

	while (*st++)
	{
		i++;
	}

	return (i);
}

/**
 * *_strcpy - copies a string
 * @dest: destination
 * @src: source
 * @n: amount of char be cpoied
 * Return: pointer to dest
 */

char *_strcpy(char *dest, const char *src, int n)
{
	int i,j;
	char *or_dest = dest;
	i = 0;
	
	while (src[i] != '\0' && i < n -1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (or_dest);
}

/**
 * *_strcat - conc string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	char *por = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}

	*dest = *src;

	return (por);
}

/**
 * _strcmp - comparison between two string
 * @st1: first string
 * @st2: sec string
 * Return: posative if st1 > st2, negative if st1 < st2, zero if st1 == st2
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}

	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * *_strdup - duplicates a string
 * @str: string dup
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	(void)str;
	int leng = 0;
	char *por;

	if (str == NULL)
		return (NULL);
	while (*str++)
	{
		leng++;
	}

	por = malloc(sizeof(char) * (leng + 1));

	if (!por)
		return (NULL);
	for (leng++; leng--;)
		por[leng] = *--str;

	return (por);
}
