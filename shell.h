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
int my_strcmp(char *st1, char *st2);
char *my_strdup(const char *string)
char *my_strcpy(char *dest, char *src);
int my_strlen(char *st);
char *my_strcat(char *dest, char *src);

#endif
