#include "shell.h"

/**
 * _putchar - print char
 * @c: character
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * print_n - prints number
 * @n: number
 * Return: n
 */

int print_n(int n)
{
	int i = 0;
	unsigned int num;

	if (n < 0)
	{
	num = -n;
	i = i + _putchar('-');
	}
	else
	{
		num = n;
	}
	if (num / 10 != '\0')
	{
		i = i + print_n(num / 10);
	}
	i = i + _putchar(num % 10 + '0');
	return (i);
}
