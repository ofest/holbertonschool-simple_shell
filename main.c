#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0
 */

int main (void)
{

	int argc = 0, count;
	char *tmp_cmd, **argv;
	/* Command line */
	char *cmd = NULL, *token;
	/* Buffer size */
	size_t size = 0;
	/* Char read */
	ssize_t num_char;
	char *prompt = "($) ";
	pid_t pid;
	int status;


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

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (0);
		}
		else if (pid == 0)
		{
			/* Processus enfant */
			printf("Before execve\n");
			if (execvp(argv[0], argv) == -1)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
			printf("After execv\n");
		}
		else
		{
			/* Processus parent */
			waitpid(pid, &status, 0);
		}

		free(argv);

	}
	free(cmd);
	return (0);
}

