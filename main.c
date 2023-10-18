#include "shell.h"

/**
 * main - simple shell in c
 * Return: 0
 */

int main(void)
{
	ssize_t read = 0;
	size_t size = 0;
	char *line = NULL, *args[20];
	int count = 1, path = 0, existed = 0, status = 0, builtin = 0;

	pr_prompt("$ ", 2);
	read = getline(&line, &size, stdin);
	while (read != -1)
	{
		if (*line != '\n')
		{
			token_line(line, args);
			if (args[0] != NULL)
			{
				existed = file_exist(args[0]);
				if (existed != 0)
				{
					path = _path(args);
					if (path == 0)
						status = execute_command(args), free(line), free(*args);
					else
					{
						builtin = execute_builtin(args, status);
						if (builtin != 0)
							status = command_notfound(args, count), free(line);
					}
				}
				else
					status = execute_command(args), free(line);
			}
			else
				free(line);
		}
		else if (*line == '\n')
			free(line);
		line = NULL, count++;
		pr_prompt("$ ", 2), read = getline(&line, &size, stdin);
	}
	last_free(line);
	return (status);
}


/**
 * last_free - free line for last exec
 * @line: Input
 */

void last_free(char *line)
{
	if (isatty(STDIN_FILENO))
	{
		putchar('\n');
		free(line);
	}
	if (!isatty(STDIN_FILENO))
		free(line);
}

/**
 * pr_prompt - prints prompt
 * @prompt: pointer to string
 * @size: size of prompt
 * Return: 0
 */

int pr_prompt(const char *prompt, unsigned int size)
{
	int printed;

	if (isatty(STDIN_FILENO))
	{
		printed = write(1, prompt, size);
		if (printed == -1)
			return (-1);
	}
	return (0);
}

/**
 * command_notfound - prints error message when command not found
 * @args: array of args typed by the user
 * @count: count execution proccesses
 * Return: exit status
 */
int command_notfound(char **args, int count)
{
	char *shell_name = "hsh";
	char *shell_name_non = "./hsh";

	if (isatty(STDIN_FILENO))
		write(2, shell_name, 3);
	else
	{
		write(2, shell_name_non, 5);
	}
	write(2, ": ", 2);
	printf("%d", count);
	write(2, ": ", 2);
	write(2, args[0], strlen(args[0]));
	write(2, ": not found\n", 12);
	return (127);
}
