#include "shell.h"

/**
 * _getenv - get content of environ
 * @global: variable
 * Return: pointer to content of environ
 */

char *_getenv(char *global)
{
	int i = 0;
	const char delim[] = "=";
	char *env_copy, *envtoken, *envtoken_copy;

	if (global == NULL)
		return (NULL);
	if (environ == NULL)
		return (NULL);
	while (environ[i] != NULL)
	{
		env_copy = strdup(environ[i]);
		if (env_copy == NULL)
			return (NULL);
		envtoken = strtok(env_copy, delim);
		if (strcmp(envtoken, global) == 0)
		{
			envtoken = strtok(NULL, delim);
			if (envtoken == NULL || envtoken[i] == '\0')
			{
				free(env_copy);
				return (NULL);
			}
			envtoken_copy = strdup(envtoken);
			free(env_copy);
			return (envtoken_copy);
		}
		free(env_copy);
		i++;
	}
	return (NULL);
}
