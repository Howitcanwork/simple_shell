#include "shell.h"

/**
 * append_file - appends slash ans a file name
 * @dir: directory
 * @file: file
 * Return: path
 */

char *append_file(char *dir, char *file)
{
	char *path = malloc(strlen_f(dir) + 1 + strlen_f(file) + 1);

	if (path == NULL)
	{
		perror("error allocating memory");
		return (NULL);
	}
	*strcpy_f(path, dir);
	strcat_f(path, "/");
	*strcat_f(path, file);
	return (path);
}

/**
 * find_executable - finds full path
 * @dirs: directories
 * @command: command input
 * Return: path
 */

char *find_executable(char **dirs, char *command)
{
	int i;
	char *path;

	if (command == NULL || command[0] == '\0')
	{
		perror("error no command");
		return (NULL);
	}
	if (strchr_f(command, '/'))
	{
		return (*strdup_f(command));
	}
	for (i = 0; dirs[i] != NULL; i++)
	{
		path = append_file(dirs[i], command);
		if (path == NULL)
		{
			return (NULL);
		}
		if (access(path, X_OK) == 0)
		{
			return (path);
		}
		free(path);
	}
	return (NULL);
}
