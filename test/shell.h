#ifndef SHELL_H
#define SHELL_H

/*include libraries*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

extern char **environ;

int token_line(char *line, char **args);
int execute_command(char **args);
int execute_builtin(char **args, int status);
int my_exit(char **args);
int my_env(char **args);
int count_args(char **args);
int file_exist(char *pathname);
void last_free(char *line);
int _path(char **args);
char *join_path_command(char *dir_env, char *args);
int command_notfound(char **args, int count);
void free_grid(char **grid, int heigth);

#endif
