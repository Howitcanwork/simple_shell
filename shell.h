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

int token_line(char *line_copy, char **args);
char *read_input(char *line);
int execute_command(char **args);
int execute_builtin(char **args, int status);
int my_exit(char **args);
int my_env(char **args);
int count_args(char **args);
int file_exist(char *path);
void last_free(char *line);
int _path(char **args);
char *join_path_command(char *dir_env, char *args);
int command_notfound(char **args, int count);
void free_array(char **array, int n);
int pr_prompt(const char *prompt, unsigned int size);
char *_getenv(char *global);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *strs);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
ssize_t get_line(char **leptr, size_t *m, FILE *stream_r);
void g_line(char **leptr, size_t *m, char *buf, size_t k);
int _putchar(char c);
int print_n(int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *to, char *from, unsigned int n);
char *_strtok(char *str, char *delim);
int _strspn(char *string, char *chrs);
char *_strchr(char *s, char c);
#endif
