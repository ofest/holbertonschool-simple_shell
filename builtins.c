#include "shell.h"

/**
 * check_builtin - Checks if command is a built-in
 * @args: Array of command arguments
 * Return: 1 if built-in executed, 0 if not a built-in
 * -1 if shell should exit
 */
int check_builtin(char **args)
{
	if (args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		exit_shell(args);
		return (-1);
	}

	if (strcmp(args[0], "env") == 0)
	{
		print_env(args);
		return (1);
	}

	return (0);
}

/**
 * exit_shell - Built-in exit command
 * @args: Array of command arguments
 */
void exit_shell(char **args)
{
	(void)args;
	exit(EXIT_SUCCESS);
}

/**
 * print_env - Built-in env command
 * @args: Array of command arguments
 */
void print_env(char **args)
{
	int i;

	(void)args;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
