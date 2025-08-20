#include "shell.h"

/**
  * clean_up - Free line & args
  * @line: Command line
  * @args: Arguments from cmd line
  */
void clean_up(char *line, char **args)
{
	free(line);
	free(args);
}

/**
 * main - Entry point of the shell.
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
	char *line, **args;
	int status = 1;
	int cmd_index = 0;

	signal(SIGINT, SIG_IGN);
	while (status)

	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
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
		if (args[0] != NULL)
			cmd_index++;
		status = execute_command(args, cmd_index);
		if (status == 0 || status == -1)
		{
			clean_up(line, args);
			break;
		}
		else if (status > 1)
		{
			clean_up(line, args);
			exit(status);
		}
		clean_up(line, args);
	}
	return (0);
}

/**
  * free_argv - Free a NULL-terminated array of strings
  * @argv: Argument vector to free.
  */

void free_argv(char **argv)
{
	int i;

	if (!argv)
		return;

	for (i = 0; argv[i]; i++)
		free(argv[i]);

	free(argv);
}
