#include "shell.h"

char *read_input(void)
{
	char *lineptr;
	size_t n = 0;
	ssize_t command_read;
	char *lineptr_copy = NULL;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;
	char **argv;
	int i;

	command_read = getline(&lineptr, &n, stdin);

	if (command_read == -1)
	{
		if (feof(sydin))
		{
			free(lineptr);
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
