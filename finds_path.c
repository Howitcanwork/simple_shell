#include "shell.h"

/**
 * append_file - appends slash ans a file name
 * @dir: directory
 * @file: file
 * Return: path
 */

char *append_file(char *dir, char *file)
{
	char *path = malloc(strlen(dir) + strlen(file) + 2);

	if (path == NULL)
	{
		perror("error allocating memory");
		return (NULL);
	}
	strcpy(path, dir);
	strcat(path, "/");
	strcat(path, file);
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
	if (strchr(cmd, '/'))
	{
		return (strdup(cmd));
	}
	for (i = 0; dirs[i] != NULL; i++)
	{
		path = append_file(dirs[i], cmd);
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
