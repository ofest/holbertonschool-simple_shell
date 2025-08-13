#include "main.h"

/**
 * handle_eof - Handle Ctrl+D (EOF).
 * @read_chars: Return value of getline().
 * @cmd: Command to free if EOF.
 *
 * Return: 1 if EOF, else 0
 */

int handle_eof(ssize_t read_chars, char *cmd)
{
	if (read_chars == -1)
	{
		printf("\n");
		free(cmd);
		return (1);
	}
	printf("Commande tapée : %s", cmd); /* Debug */
	return (0);
}
