#include "shell.h"

/**
 * tokens_line - parase line from input
 * @lineptr: line read from input
 * Return: pointer to array of tokens
 */

char **tokens_line(char *lineptr)
{
	const char *delim = " \t\r\n";
	char *token;
	int buffsize = 64;
	char **parts = malloc(buffsize * sizeof(char *));
	int i = 0, j;

	if (!parts)
	{
		perror(Error: memory allocation);
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr, delim);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
		parts[i] = token;
		i++;
		if (i >= buffsize)
		{
			buffsize += buffsize;
			char **new_tokens = malloc(buffsize * sizeof(char *));

			if (!new_tokens)
			{
				perror(Error: memory allocation);
				exit(EXIT_FAILURE);
			}
			for (j = 0; j < i; j++)
			{
				new_tokens[j] = parts[j];
			}
			free(parts);
			parts = new_tokens;
		}
		token = strtok(NULL, delim);
	}
	parts[i] = NULL;
	return (parts);
}
