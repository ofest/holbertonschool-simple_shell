#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Function prototypes */
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
int check_builtin(char **args);
void exit_shell(char **args);
void print_env(void);
char *find_path(char *command);
int file_exists(char *filepath);
char *exec_full_path(char *command, char *dir);
int fork_process(char *command_path, char **args);
char *get_path(void);

/* Global variables */
extern char **environ;

#endif
