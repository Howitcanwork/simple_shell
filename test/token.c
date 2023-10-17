#include "shell.h"

/**
 * token_line - parase line from input
 * @line: input
 * @args: array 
 * Return: length of array
 */

int token_line(char *line, char **args)
{
        const char *delim = " \n\t\r";
        int i = 0;
        char *command, *token;
	char *ptr = line;
        char *line_copy = strdup(line);
        
	if (line_copy == NULL)
	{
		perror("strdup failed");
		return (-1);
	}
        command = strtok(line_copy, delim);
	if (command == NULL)
	{
		free(line_copy);
		return (0);
	}
        args[i] = command;
        while (ptr != NULL)
        {
                if (command[0] == '#')
                {
                        break;
                }
                i++;
                token = strtok(NULL, delim);
                ptr = token;
                args[i] = token;
        }
        args[i] = NULL;
        return (i);
}

/**
 * _exist - check if file exist
 * @pathname: path to the file
 * Return: 0 iffile exist, -1 otherwise
 */
 
int file_exist(char *pathname)
{
	int status;

	status = (open(pathname, O_RDONLY));
	if (status != -1)
	{
		close(status);
		return (0);
	}
	else
		return (-1);
}
