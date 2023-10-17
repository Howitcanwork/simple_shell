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

/*functions prototybes*/
char *read_input(void);
char **tokens_line(char *lineptr);
int execute_arguments(char **args);
int my_exit(char **argc);
char *append_file(char *dir, char *file);
char *find_executable(char **dirs, char *command);
void *my_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *my_memcpy(char *to, char *from, unsigned int n);
char **parse_path(char *path);
int new_process(char **args);
int my_env(char **argc);
int _path(char **args);
char *join_path_command(char *dir_env, char *args);
int _exist(char *pathname);

int strlen_f(char *s);
char *strdup_f(const char *s);
char *strcpy_f(char *dest, char *src);
char *strchr_f(char *s, char c);
int strcmp_f(char *s1, char *s2);
char *strcat_f(char *dest, char *src);

#endif
