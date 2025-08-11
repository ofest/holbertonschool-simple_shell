#include "main.h"

/**
 * main - Manage start.
 * @argc: Argument count.
 * @argv: Argument value>
 *
 * Return: 0
 */

int main (void)
{
	/* Command line */
	char *cmd = NULL;
	/* Buffer size */
	size_t size = 0;
	/* Char read */
	ssize_t num_char;

	while(1)
	{
		printf("($) ");
		/* Read command */
		num_char = getline(&cmd, &size, stdin);
		/* ctrl + d */
		if (num_char == -1)
		{
			printf("\n");
			break;
		}
		printf("Commande tapée : %s", cmd);
	}
	free(cmd);
	return (0);
}
