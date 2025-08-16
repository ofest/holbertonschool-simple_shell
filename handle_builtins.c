#include "main.h"

/**
 * handle_builtins - Handle built-in commands.
 * @argv: Argument values.
 * @envp: Environnement variables.
 *
 * Return: 0 on error, 1 if cmd executed, 2 for exit.
 */

int handle_builtins(char **argv, char **envp)
{
	int i;

	if (!argv || !argv[0])
		return (0);

	if (strcmp(argv[0], "exit") == 0)
	{
		return (2);
	}
	else if (strcmp(argv[0], "env") == 0)
	{
		for (i = 0; envp[i]; i++)
		{
			printf("%s\n", envp[i]);
		}
		return (1);
	}
	return (0);
}
