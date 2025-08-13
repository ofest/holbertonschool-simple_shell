#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0
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
		printf("Commande tapée : %s\n", cmd); /* Debug */
		printf("%s", prompt);

		/* Read command */
		read_chars = getline(&cmd, &size, stdin);

		/* Count number of arguments */
		count = arg_counter(cmd);
		if (!count || count == 0)
			return (0);

		/* Fill argv */
		argv = arg_filler(count, cmd);
		if (!argv)
			return (0);

		/* Check if cmd exist */
		path_checker(argv);

		/* Fork pid */
		fork_pid(argv);

		/* Handle eof in a file */
		if (handle_eof(read_chars, cmd, argv))
			return (0);
		free(argv);
	}
	free(cmd);
	return (0);
}
