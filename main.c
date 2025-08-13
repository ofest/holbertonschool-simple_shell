#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0 on success, 1 on error
 */

int main(void)
{
	int count;
	char **argv;
	char *cmd = NULL;
	size_t size = 0;
	ssize_t read_chars;
	char *prompt = "($) ";

	while (1)
	{
		printf("%s", prompt);

		/* Read command */
		read_chars = getline(&cmd, &size, stdin);
		if (read_chars == -1)
		{
			printf("\n");
			free(cmd);
			return (0);
		}

		/* Remove newline from command */
		if (cmd[read_chars - 1] == '\n')
			cmd[read_chars - 1] = '\0';

		/* Skip empty commands */
		if (strlen(cmd) == 0)
			continue;

		/* Count number of arguments */
		count = arg_counter(cmd);
		if (count <= 0)
			continue;

		/* Fill argv */
		argv = arg_filler(count, cmd);
		if (!argv)
			continue;

		/* Handle built-in commands */
		if (handle_builtins(argv) == 1)
			continue;
		else if (handle_builtins(argv) == 2)
			return (0);

		/* Check if command exists and execute */
		if (execute_command(argv) == -1)
		{
			fprintf(stderr, "hsh: command not found: %s\n", argv[0]);
		}

		free(argv);
	}
	free(cmd);
	return (0);
}
