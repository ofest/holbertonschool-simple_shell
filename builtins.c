#include "shell.h"

/**
 * check_builtin - Checks if command is a built-in
 * @args: Array of command arguments
 * Return: 1 if built-in executed and continue, 0 if not a built-in,
 *         -1 if shell should exit, or exit status code from args[1]
 */
int check_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1])
			return (atoi(args[1]));
		return (-1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
}

/**
 * print_env - Built-in env command
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
