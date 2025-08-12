#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0
 */

int main (void)
{
	int argc = 0, count, i;
	char *tmp_cmd, **argv;
	/* Command line */
	char *cmd = NULL, *token;
	/* Buffer size */
	size_t size = 0;
	/* Char read */
	ssize_t num_char;
	char *prompt = "($) ";

	while (1)
	{
		printf("%s", prompt);

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

		tmp_cmd = strdup(cmd);

		/* Count arg number */
		token = strtok(tmp_cmd, " \n");
		for (count = 0; token;)
		{
			count++;
			token = strtok(NULL, " \n");
		}
		printf("Arg number : %i\n", count); /* Debug */
		free(tmp_cmd);

		/* Allocate space */
		argv = malloc(sizeof(char *) * (count + 1));
		if (!argv)
		{
			free(cmd);
			return (0);
		}

		/* Fill argv */
		argc = 0;
		token = strtok(cmd, " \n");
		while (token)
		{
			argv[argc++] = token;
			token = strtok(NULL, " \n");
		}
		argv[argc] = NULL;

		/* Check if tty */
		if (isatty(STDIN_FILENO))
		{
			printf("Mode interactif\nargc = %i\n", argc); /* Debug */
			for (i = 0; i < argc; i++) /* Debug */
			{ /* Debug */
				printf("argv[%d] = %s\n", i, argv[i]); /* Debug */
			} /* Debug */
			
			free(argv);
		}
		else
		{
            execvp(argv[0], argv);
            perror("Error executing command"); 
            return (-1);
		}
	}
	free(cmd);
	return (0);
}