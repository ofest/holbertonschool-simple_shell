#ifndef _SHELL_H_
#define _SHELL_H_

/* Standard libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Global environment */
extern char **environ;

/* Function prototypes */
char *_strdup(char *str);
int arg_counter(char *cmd);
char **arg_filler(int count, char *cmd);
char *path_checker(char *cmd);
int execute_command(char **argv, char **envp);
int handle_builtins(char **argv, char **envp);
void free_argv(char **argv);

#endif
