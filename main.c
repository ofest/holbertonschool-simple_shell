#include "main.h"

/**
 * main - Main loop.
 *
 * Return: 0
 */

int main (void)
{
	int count, i;
	char **argv;
	/* Command line */
	char *cmd = NULL;
	/* Buffer size */
	size_t size = 0;
	/* Char read */
	ssize_t read_chars;
	/* Prompt sign */
	char *prompt = "($) ";
	/* pid / fork vars */
	pid_t pid;
	int status;
	/* cmd exist */
	struct stat st;

	while (1)
	{
		printf("%s", prompt);

		/* Read command */
		read_chars = getline(&cmd, &size, stdin);

		/* Handle eof in a file */
		if (handle_eof(read_chars, cmd))
		    return (0);

		/* Count number of arguments */
		count = arg_counter(cmd);
		if (!count || count == 0)
			return (0);

		/* Fill argv */
		argv = arg_filler(count, cmd);
		if (!argv)
		    return (0);

		/* check if cmd exist */
		printf("Before stat\n");
		for (i = 0; argv[i]; i++)
		{
			if (stat(argv[i], &st) == 0)
				printf(" Found\n");
			else
				printf(" Not found\n");
		}	

		/* fork pour execute */
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
