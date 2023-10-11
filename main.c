#include "shell.h"

/**
 * main - entry point
 * Return: nothing
 */

int main(void)
{
	char *prompt = "mainoon_shell$ ";
	char *lineptr;
	char **args;
	int state = -1;

	while (1)
	{
		printf("%s", prompt);
		lineptr = read_input();
		args = tokens_line(lineptr);
		state = execute_arguments(args);
	}
	free(lineptr);
	free(args);
	if (state >= 0)
	{
		exit(state);
	}
}
