#include "shell.h"

/**
 * display_prompt - Displays the shell prompt
 */
void display_prompt(void)
{
	write(STDOUT_FILENO, "($) ", 4);
}

/**
 * read_line - Reads a line from stdin
 * Return: Pointer to the line, or NULL on EOF
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read_size;

	read_size = getline(&line, &len, stdin);
	if (read_size == -1)
	{
		free(line);
		return (NULL);
	}

	/* Remove newline character */
	if (line[read_size - 1] == '\n')
		line[read_size - 1] = '\0';

	return (line);
}

/**
 * parse_line - Parses a line into arguments
 * @line: The line to parse
 * Return: Array of arguments, or NULL on error
 */
char **parse_line(char *line)
{
	char **args = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (args == NULL)
		return (NULL);

	token = strtok(line, " \t\r\n");
	while (token != NULL && i < 63)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " \t\r\n");
	}
	args[i] = NULL;

	return (args);
}

/**
 * execute_command - Executes a command
 * @args: Array of command arguments
 * Return: 1 to continue, 0 to exit
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *command_path;
	int builtin_status;

	if (args[0] == NULL)
		return (1);

	/* Check for built-in commands */
	builtin_status = check_builtin(args);
	if (builtin_status != 0)
	{
		if (builtin_status < 0 || builtin_status > 1)
			return (0);
		return (1);
	}

	/* Find command in PATH */
	command_path = find_path(args[0]);
	if (command_path == NULL)
	{
		write(STDERR_FILENO, "./hsh: 1: ", 10);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		return (1);
	}

	/* Fork process */
	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execve(command_path, args, environ) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		/* Fork failed */
		perror("fork");
		return (1);
	}
	else
		wait(&status);
	if (command_path != args[0])
		free(command_path);
	return (1);
}
