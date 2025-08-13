#include "main.h"

/**
 * arg_filler - Fill argv[argc] with commands.
 * @count: number of arguments.
 * @cmd: Inputed commands.
 *
 * Return: argv
 */

char **arg_filler(int count, char *cmd)
{
	int argc = 0;
	char **argv, *token;

	/* Allocate space */
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
	{
		perror("malloc");
		return (NULL);
	}

	/* Fill argv & argc */
	token = strtok(cmd, " \n");
	while (token)
	{
		argv[argc++] = token;
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;

	return (argv);
}
