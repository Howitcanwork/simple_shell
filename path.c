#include "shell.h"

/**
 * _path - check if command can be executed
 * @args: arguments
 * Return: 0
 */

int _path(char **args)
{
	char *path_env = NULL;
	char *dir_env = NULL;
	char *command_path = NULL;
	int command_exist = -1;

	path_env = getenv("PATH");
	if (path_env == NULL)
		return (-1);
	dir_env = strtok(path_env, ":");
	while (dir_env != NULL && command_exist == -1)
	{
		command_path = join_path_command(dir_env, args[0]);
		command_exist = _exist(command_path);
		dir_env = strtok(NULL, ":");
	}
	if (command_exist == 0)
	{
		args[0] = command_path;
		free(path_env);
		return (0);
	}
	else
	{
		free(path_env);
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
	int i = 0, j = 0;
	int path_len, cmd_len;
	char *joined;

	if (!dir_env || !args)
		return (NULL);
	path_len = strlen(dir_env);
	cmd_len = strlen(args);
	joined = malloc(path_len + cmd_len + 2);
	if (!joined)
		return (NULL);
	while (dir_env[i] != '\0')
	{
		joined[i] = dir_env[i];
		i++;
	}
	if (dir_env[i - 1] != '/')
	{
		joined[i] = '/';
		i++;
	}
	while (args[j] != '\0')
	{
		joined[i + j] = args[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

/**
 * _exist - check if file exist
 * @pathname: path to file
 * Return: 0 if file exist -1 if not
 */

int _exist(char *pathname)
{
	int status;

	status = open(pathname, O_RDONLY);
	if (status != -1)
	{
		close(status);
		return (0);
	}
	else
	{
		return (-1);
	}
}
