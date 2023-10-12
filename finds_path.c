#include "shell.h"

/**
 * append_file - appends slash ans a file name
 * @dir: directory
 * @file: file
 * Return: path
 */

char *append_file(char *dir, char *file)
{
	char *path = malloc(my_strlen(dir) + 1 + my_strlen(file) + 1);

	if (path == NULL)
	{
		perror("error allocating memory");
		return (NULL);
	}
	my_strcpy(path, dir);
	my_strcat(path, "/");
	my_strcat(path, file);
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
	if (strchr(command, '/'))
	{
		return (my_strdup(command));
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
