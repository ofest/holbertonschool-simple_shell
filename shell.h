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
void display_prompt(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args);
int check_builtin(char **args);
void exit_shell(char **args);
void print_env(char **args);
char *find_path(char *command);
int file_exists(char *filepath);
char *exec_full_path(char *command, char *dir);

/* Global variables */
extern char **environ;

#endif
