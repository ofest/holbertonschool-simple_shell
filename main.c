#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0
 */

int main (void)
{
	int argc = 0, i;
	char *argv[100]; /* 100 is arbitrary -> have to manage it later */
	/* Command line */
	char *cmd = NULL, *token;
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
			free(cmd);
			return (0);
		}
		printf("Commande tapée : %s", cmd); /* Debug */

		/* Split command line into words */
		token = strtok(cmd, " \n");
		while (token && argc < 99)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		/* End list with NULL */
		argv[argc] = NULL;

		if (isatty(STDIN_FILENO))
		{
			printf("Mode interactif argc = %i\n", argc); /* Debug */
			for (i = 0; i < argc; i++) /* Debug */
			{
				printf("argv[%d] = %s\n", i, argv[i]);
			}
			/*interactive(argc, argv);*/
		}
		else
		{
			printf("Mode non interactif\n"); /* Debug */
			/*n_interactive(argc, argv);*/
		}

		while (token) /* Debug */
		{
			printf("Token : %s\n", token);
			token = strtok(NULL, " \n");
		}
	}
	free(cmd);
	return (0);
}
