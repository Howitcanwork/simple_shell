#include "shell.h"

/**
 * execute_arguments - commans builtin or process
 * @args: command
 * Return: 0
 */

int ececute_arguments(char **args)
{
	char *builtin_command[] = {
		"cd",
		"env",
		"help",
		"exit"
	};
	int (*builin_comm[])(char **) = {
		&own_cd,
		&own_env,
		&own_help,
		&own_exit
	};
	int i = 0;

	if (args[0] == NULL)
	{
		return (-1);
	}
	for (i = 0; i < sizeof(builtin_command) / sizeof(char *); i++)
	{
		if (strcmp(args[0], builtin_commands[i]) == 0)
		{
			return ((*builtin_comm[i])(args));
		}
	}
	return (new_process(args));
}
