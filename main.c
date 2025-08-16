#include "shell.h"

/**
 * main - Entry point of the shell.
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	char *line;
	char **args;
	int status = 1;

	/* Set up signal handling */
	signal(SIGINT, SIG_IGN);

	while (status)
	{
		/* Display prompt in interactive mode */
		if (isatty(STDIN_FILENO))
			display_prompt();
		/* Read command line */
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		/* Parse command line */
		args = parse_line(line);
		if (args == NULL)
		{
			free(line);
			continue;
		}
		/* Execute command */
		status = execute_command(args);
		/* Clean up */
		free(line);
		free(args);
	}
	return (0);
}
