#include "shell.h"

/**
 * _getenv - Get content of global variable
 * @global_var: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */

/**char *_getenv(char *global_var)
  {
  int i = 0;
  const char split[] = "=";
  char *env_tok, *envdup, *env_tok_dup;

  if (global_var != NULL)
  {
  if (environ == NULL)
  return (NULL);
  envdup = strdup(environ[i]);
  while (environ[i] != NULL)
  {
  envdup = strdup(environ[i]);
  if (envdup == NULL)
  return (NULL);
  env_tok = strtok(envdup, split);
  if (strcmp(env_tok, global_var) == 0)
  {
  env_tok = strtok(NULL, split);
  if (env_tok == NULL || env_tok[0] == '\0')
  {
  free(envdup);
  return (NULL);
  }
  env_tok_dup = strdup(env_tok);
  free(envdup);
  return (env_tok_dup);
  }
  free(envdup);
  }
  }
  return (NULL);
  }*/

#include "shell.h"
/**
 * _getenv - Get content of global variable
 * @global_var: Variable to extract from environ
 * Return: Pointer to the content of a variable, or NULL if fails
 */

char *_getenv(char *global_var)
{
	int i = 0;
	const char split[] = "=";
	char *env_tok, *envdup, *env_tok_dup;

	if (global_var == NULL)
		return (NULL);
	if (environ == NULL)
		return (NULL);

	while (environ[i] != NULL)
	{
		envdup = strdup(environ[i]);
		if (envdup == NULL)
			return (NULL);

		env_tok = strtok(envdup, split);
		if (strcmp(env_tok, global_var) == 0)
		{
			env_tok = strtok(NULL, split);
			if (env_tok == NULL || env_tok[0] == '\0')
			{
				free(envdup);
				return (NULL);
			}
			env_tok_dup = strdup(env_tok);
			free(envdup);
			return (env_tok_dup);
		}
		free(envdup);
		i++;
	}

	return (NULL);
}

/**
 * my_getenv - get content of global variable
 * @glob_var: variable extracted
 * Return: pointer to content of var or NULL
 */

char *my_getenv(const char *glob_var)
{
	int i;
	char *name, *value;

	for (i = 0; environ[i] != NULL; i++)
	{
		if (environ == NULL)
		{
			perror("environ");
			return (NULL);
		}
		name = strtok(environ[i], "=");
		value = strtok(NULL, "=");
		if (strcmp(name, glob_var) == 0)
		{
			return (value);
		}
	}
	return (NULL);
}
