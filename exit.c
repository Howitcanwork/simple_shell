#include "shell.h"

/**
 * my_exit - exit builtin command
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: nothing
 */

int my_exit(int argc, char **argv)
{
	(void)argv;

	if (argc == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "exit: too many arguments\n", 25);
		return (EXIT_FAILURE);
	}
}
