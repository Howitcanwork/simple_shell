#ifndef SHELL_H
#define SHELL_H

/*include libraries*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/*functions prototybes*/
char *read_input(void);
char **tokens_line(char *lineptr);

#endif
