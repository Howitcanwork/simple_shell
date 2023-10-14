#include "shell.h"

/**
 * execute_arguments - commans builtin or process
 * @args: command
 * Return: 0
 */

int execute_arguments(char **args)
{
	char *builtin_command[] = {
		"env",
		"exit",
		NULL
	};
	int (*builtin_comm[])(char **) = {
		&my_env,
		&my_exit
	};
	int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	while (builtin_command[i] != NULL)
	{
		if (strcmp(args[0], builtin_command[i]) == 0)
		{
			return ((*builtin_comm[i])(args));
		}
		i++;
	}
	return (new_process(args));
}

/**
 * my_exit - exit builtin command
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: nothing
 */

int my_exit(char **argc)
{
	if (argc[1])
	{
		free(argc);
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "exit: too many arguments\n", 25);
		return (EXIT_FAILURE);
	}
}

/**
 * my_env - implement the env builtin
 * Return: nothing
 */

int my_env(char **argc)
{
	int i = 0;
	int length = 0;
	(void)(**argc);

	while (environ[i])
	{
		length = strlen(environ[i]);
		write(1, environ[i], length);
		i++;
	}
	return (0);
}
