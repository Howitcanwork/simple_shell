#include "shell.h"

/**
 * my_exit - exit builtin command
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: nothing
 */

void my_exit(int argc, char **argv)
{
	if (argc == 1)
	{
		exit(0);
	}
	else
	{
		write(2, "exit: too many arguments\n", 25);
		return (1);
	}
}
