#include "shell.h"

/**
 * new_procss - create new process
 * @args: array of commands
 * Return: 1 success
 */

int new_process(char **args)
{
	pid_t pid;
	int status, execute = 0;
	char *path = getenv("PATH");
	char **dirs = parse_path(path);
	char *all_path;

	all_path = _path(dirs);
	pid = fork();
	if (pid == 0)
	{
		execute = execve(all_path, args, environ);
		if (execute == -1)
		{
			perror("error while processing");
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in forking");
	}
	else
	{
		do {
			waitpid(pid ,&status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(dirs);
	free(all_path);
	return (0);
}

/**
 * parse_path - parases path environment
 * @path: path
 * Return: array of directories
 */
char **parse_path(char *path)
{
	char *path_copy = strdup(path);
	char *p, *token;
	int colons = 0, i = 0;
	char **dirs;

	if (path == NULL || path[0] == '\0')
	{
		return (NULL);
	}
	if (path_copy == NULL)
	{
		perror("error in copy");
		return (NULL);
	}
	for (p = path_copy; *p != '\0'; p++)
	{
		if (*p == ':')
		{
			colons++;
		}
	}
	dirs = malloc((colons + 2) * sizeof(char *));
	if (dirs == NULL)
	{
		perror("error allocating memmory");
		free(path_copy);
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		dirs[i] = token;
		i++;
		token= strtok(NULL, ":");
	}
	dirs[i] = NULL;
	free(path_copy);
	return (dirs);
}
