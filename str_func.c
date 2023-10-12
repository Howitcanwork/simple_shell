#include "shell.h"

/**
 * my_strlen - length of string
 * @st: string
 * Return: int of string length
 */

int my_strlen(char *st)
{
	int j = 0;

	if (!st)
		return (0);
	while (*st++)
		j++;

	return (j);
}

/**
 * my_strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *my_strcpy(char *dest, char *src)
{
	int j = 0;

	if(dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}

	dest[j] = 0;

	return (dest);
}

/**
 * my_strcat - conc string
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *my_strcat(char *dest, char *src)
{
	char *por = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;

	*dest = *src;

	return (por);
}

/**
 * my_strcmp - comparison between two string
 * @st1: first string
 * @st2: sec string
 * Return: posative if st1 > st2, negative if st1 < st2, zero if st1 == st2
 */
int my_strcmp(char *st1, char *st2)
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
 * my_strdup - duplicates a string
 * @string: string dup
 * Return: pointer to the duplicated string
 */

char *my_strdup(const char *string)
{
	int leng = 0;
	char *por;

	if (string == NULL)
		return (NULL);
	while (*string++)
		leng++;

	por = malloc(sizeof(char) * (leng + 1));

	if (!por)
		return (NULL);
	for (leng++; leng--;)
		por[leng] = *--string;

	return (por);
}
