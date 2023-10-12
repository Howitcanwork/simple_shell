#include "shell.h"

/**
 * tokens_line - parase line from input
 * @lineptr: line read from input
 * Return: pointer to array of tokens
 */

char **tokens_line(char *lineptr)
{
	const char *delim = " \t\r\n";
	int buffsize = 64, i = 0, j;
	char **parts = malloc(buffsize * sizeof(char *));
	char *token, **new_tokens;
	char *lineptr_copy = _strdup(lineptr);

	if (!parts || !lineptr_copy)
	{
		perror("memory allocation error");
		exit(EXIT_FAILURE);
	}
	token = strtok(lineptr_copy, delim);
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
			new_tokens = malloc(buffsize * sizeof(char *));
			if (!new_tokens)
			{
				perror("memory allocation error");
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
	printf("%s\n", lineptr);
	parts[i] = NULL;
	free(lineptr_copy);
	return (parts);
}
