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

/*functions prototybes*/
char *read_input(void);
char **tokens_line(char *lineptr);
int execute_arguments(char **args);
int my_exit(int argc, char **argv);
char *append_file(char *dir, char *file);
char *find_executable(char **dirs, char *command);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *my_memcpy(char *to, char *from, unsigned int n);
char **parse_path(char *path);
int new_process(char **args);
int _strcmp(char *st1, char *st2);
char *_strdup(const char *str)
char *_strcpy(char *dest, char *src);
int _strlen(char *st);
char *_strcat(char *dest, char *src);

#endif
