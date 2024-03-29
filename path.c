#include "shell.h"

/**
 * _path - check if command can be executed
 * @args: arguments
 * Return: 0
 */
int _path(char **args)
{
	char *path_env, *path_copy, *dir_env, *command_path, *array[121];
	int command_exist = -1, i = 0;

	path_env = _getenv("PATH");
	if (path_env == NULL)
	{
		return (-1);
	}
	path_copy = _strdup(path_env);
	dir_env = strtok(path_copy, ":");
	if (dir_env == NULL)
		return (-1);
	free(path_env);
	while (dir_env != NULL && command_exist == -1)
	{
		command_path = join_path_command(dir_env, args[0]);
		if (command_path == NULL)
		{
			perror("join path command");
			free(path_env);
			return (-1);
		}
		array[i] = command_path;
		command_exist = file_exist(array[i]);
		dir_env = strtok(NULL, ":");
		i++;
	}
	i--;
	free(path_copy);
	free_array(array, i);
	if (command_exist == 0)
	{
		args[0] = command_path;
		return (0);
	}
	else
	{
		free(command_path);
		return (-1);
	}
}

/**
 * join_path_command - join a directory path and a command
 * @dir_env: string to be added
 * @args: command
 * Return: joined string
 */
char *join_path_command(char *dir_env, char *args)
{
	int path_len, cmd_len;
	char *joined;

	if (!dir_env || !args)
		return (NULL);
	path_len = _strlen(dir_env);
	cmd_len = _strlen(args);
	joined = malloc(path_len + cmd_len + 2);
	if (!joined)
		return (NULL);
	strcpy(joined, dir_env);
	if (dir_env[path_len - 1] != '/')
	{
		joined[path_len] = '/';
		joined[path_len + 1] = '\0';
	}
	_strcat(joined, args);
	return (joined);
}

/**
 * free_array - function that frees an array
 * @array: pointer to array
 * @n: array height
 */

void free_array(char **array, int n)
{
	int i = 0;

	if (array == NULL)
	{
		return;
	}

	while (i < n)
	{
		free(array[i]);
		i++;
	}
}
