#include "main.h"

/**
 * select_command_path - Resolve command path and check if executable.
 * @cmd: Command name.
 * @exit_status: Pointer to store exit status.
 *
 * Return: Full path if found, NULL if not found.
 */
char *select_command_path(char *cmd, int *exit_status)
{
	char *full_path;
	struct stat st;

	if (!cmd)
	{
		*exit_status = 127;
		return (NULL);
	}

	/* Check if it's a direct path */
	if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) &&
		(st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
	{
		return (_strdup(cmd));
	}

	/* Check in PATH */
	full_path = path_checker(cmd);
	if (!full_path)
	{
		*exit_status = 127;
		return (NULL);
	}

	return (full_path);
}

/**
 * execute_command - Execute a command.
 * @argv: Argument values.
 * @envp: Environment values.
 * @exit_status: Pointer to store exit status.
 *
 * Return: 0 on success, -1 on failure.
 */
int execute_command(char **argv, char **envp, int *exit_status)
{
	int status;
	pid_t pid;
	char *full_path;

	if (!argv || !argv[0])
		return (-1);

	/* Resolve command path first */
	full_path = select_command_path(argv[0], exit_status);
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
		execve(full_path, argv, envp);
		perror("execve");
		free(full_path);
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			*exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			*exit_status = 128 + WTERMSIG(status);
	}

	free(full_path);
	return (0);
}
