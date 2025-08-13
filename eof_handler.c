#include "main.h"

/**
 * handle_eof - Handle Ctrl+D (EOF).
 * @read_chars: Return value of getline().
 * @argv: Argument values.
 *
 * Return: 1 if EOF, else 0
 */

int handle_eof(ssize_t read_chars, char *cmd, char **argv)
{
	if (read_chars == -1 || strcmp(argv[0], "exit") == 0)
	{
		printf("\n");
		free(cmd);
		return (1);
	}
	return (0);
}
