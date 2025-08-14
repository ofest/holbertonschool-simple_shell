#include "main.h"

/**
 * execute_command - Execute a command.
 * @argv: Argument values.
 *
 * Return: 0 on success, -1 on failure.
 */

int execute_command(char **argv)
{
	int status;
	pid_t pid;
	char *full_path;

	if (!argv || !argv[0])
		return (-1);

	/* Check if command exists */
	full_path = path_checker(argv[0]);
	if (!full_path)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(full_path);
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(full_path, argv, environ) == -1)
		{
			perror("execve");
			free(full_path);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
	}

	free(full_path);
	return (0);
}
