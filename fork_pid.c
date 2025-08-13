#include "main.h"

/**
 * fork_pid - Create chilf pid.
 * @argv: Argument values.
 *
 * Return: 1 on success, 0 on faillure.
 */

int fork_pid(char **argv)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		/* Child rocess */
		printf("Before execve\n"); /* Debug */
		if (execvp(argv[0], argv) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
		printf("After execv\n");/* Debug */
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}
	return (1);
}
