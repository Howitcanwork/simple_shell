#include "shell.h"
/**
 * *read_input - function
 * @line: pointer
 * Return: pointer
 */
char *read_input(char *line)
{
	size_t n = 0;
	ssize_t read;
	size_t rm;

	read = getline(&line, &n, stdin);
	if (*line == '\n')
	{
		putchar('\n');
	}
	if (read == -1)
	{
		if (feof(stdin))
		{
			perror("Exiting shell");
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading line from input");
			exit(EXIT_FAILURE);
		}
	}
	rm = strcspn(line, "\n/");
	line[rm] = '\0';
	return (line);
}
