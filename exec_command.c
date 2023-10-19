#include "shell.h"

/**
 * execute_command - create new process
 * @args: array of commands
 * Return: 1 success
 */

int execute_command(char **args)
{
	pid_t pid;
	int status;
	int exec_status;

	pid = fork();
	if (pid == -1)
	{
		perror("failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		exec_status = execve(args[0], args, environ);
		if (exec_status == -1)
		{
			perror("error while processing");
			exit(EXIT_FAILURE);
		}
		exit(0);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	exec_status = WEXITSTATUS(status);
	return (exec_status);
}

/**
 * execute_builtin - cheack if command builtin then execute it
 * @args: command
 * @status: int
 * Return: 0
 */

int execute_builtin(char **args, int status)
{
	char *builtin_commands[2] = {
		"env",
		"exit"
	};
	int i = 0, j;

	if (args[0] == NULL)
	{
		return (-1);
	}
	while (i < 2)
	{
		if (_strcmp(args[0], builtin_commands[i]) == 0)
			break;
		i++;
	}
	if (i == 2)
		return (-1);
	if (_strcmp(builtin_commands[i], "exit") == 0)
	{
		free(args[0]);
		exit(status);
	}
	if (_strcmp(builtin_commands[i], "env") == 0)
	{
		for (j = 0; environ[j]; j++)
		{
			write(1, environ, _strlen(environ[j]));
			write(1, "\n", 1);
		}
		return (1);
	}
	return (0);
}

/**
 * my_exit - exit builtin command
 * @args: number of arguments
 * Return: nothing
 */

int my_exit(char **args)
{
	register int count;

	count = count_args(args);
	if (count == 1)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		write(2, "exit: too many arguments\n", 25);
		return (EXIT_FAILURE);
	}
}

/**
 * count_args - number of arguments
 * @args: array
 * Return: number of strings
 */
int count_args(char **args)
{
	register int i = 0;

	while (args[i] != NULL)
	{
		i++;
	}
	return (i);
}
