#include "shell.h"

/**
 * main - entry point
 * Return: nothing
 */

int main(void)
{
	char *prompt = "mainoon_shell$ ";

	while (1)
	{
		printf("%s", prompt);
		read_input();
		token_line(lineptr);
	}
}
