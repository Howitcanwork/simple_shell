#include "shell.h"

/**
 * main - entry point
 * Return: nothing
 */

int main(void)
{
	char *prompt = "mainoon_shell$ ";
	char *lineptr;

	while (1)
	{
		printf("%s", prompt);
		lineptr = read_input();
		tokens_line(lineptr);
	}
}
