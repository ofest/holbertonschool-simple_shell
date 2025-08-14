#include "main.h"

/**
 * arg_filler - Fill argv[argc] with commands.
 * @count: number of arguments.
 * @cmd: Inputed commands.
 *
 * Return: argv on success, NULL on failure.
 */

char **arg_filler(int count, char *cmd)
{
	int argc = 0;
	char **argv, *token, *tmp_cmd;

	if (!cmd || count <= 0)
		return (NULL);

	/* Allocate space */
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
	{
		free(argv);
		perror("malloc");
		return (NULL);
	}
	/* Create a copy of cmd to avoid modifying original */
	tmp_cmd = _strdup(cmd);
	if (!tmp_cmd)
	{
		free(argv);
		return (NULL);
	}

	/* Fill argv & argc */
	token = strtok(tmp_cmd, " \n");
	for (; token && argc < count; argc++)
	{
		argv[argc] = _strdup(token);
		if (!argv[argc])
		{
			/* Clean up on error */
			while (argc > 0)
				free(argv[--argc]);
			free(argv);
			free(tmp_cmd);
			return (NULL);
		}
		token = strtok(NULL, " \n");
	}
	argv[argc] = NULL;
	free(tmp_cmd);
	return (argv);
}
