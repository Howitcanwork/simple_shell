#include "shell.h"

/**
 * *_strtok - function
 * @str: string
 * @delim: delimiter
 * Return: pointer string
 */
char *_strtok(char *str, char *delim)
{
	char c;
	static char *last;

	if (str == NULL)
	{
		str = last;
	}
	do {
		c = *str++;
		if (!c)
		{
			return (NULL);
		}
	} while (_strchr(delim, c));
	str--;

	last = str + _strspn(str, delim);
	if (*last)
	{
		*last = 0;
	}
	return (str);
}

/**
 * _strspn - return first occurance of any char
 * @string: input string to search
 * @chars: input chars to check
 * Return: pointer
 */

int _strspn(char *string, char *chars)
{
	char c;
	char *ptr, *_str;

	for (_str = string, c = *_str; c; _str++, c = *_str)
	{
		for (ptr = chars; *ptr; ptr++)
		{
			if (c == *ptr)
			{
				return (_str - string);
			}
		}
	}
	return (_str - string);
}
