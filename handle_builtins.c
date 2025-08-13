#include "main.h"

/**
 * handle_builtins - Handle built-in commands.
 * @argv: Argument values.
 *
 * Return: 1 if built-in command was executed, 0 otherwise.
 */

int handle_builtins(char **argv)
{
	extern char **environ;
	int i;

	if (!argv || !argv[0])
	{
		free(argv);
		return (0);
	}

	if (strcmp(argv[0], "exit") == 0)
	{
		return (2);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		for (i = 0; environ[i]; i++)
		{
			printf("%s\n", environ[i]);
		}
		return (1);
	}
	return (0);
}
