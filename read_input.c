#include "shell.h"

char *read_input(void)
{
	char *lineptr;
	size_t n = 0;
	ssize_t command_read;

	command_read = getline(&lineptr, &n, stdin);

	if (command_read == -1)
	{
		if (feof(stdin))
		{
			free(lineptr);
			perror("Exiting shell");
			exit(EXIT_SUCCESS);
		}
		else
		{
		free(lineptr);
		perror("Error reading line from input");
		exit(EXIT_FAILURE);
		}
	}
	return (lineptr);
}
