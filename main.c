#include "shell.h"

/**
 * main - Entry point of the shell.
 * Return: 0 on success, 1 on error.
 */
int main(void)
{
<<<<<<< HEAD
<<<<<<< HEAD

	int argc = 0, count;
	char *tmp_cmd, **argv;
	/* Command line */
	char *cmd = NULL, *token;
	/* Buffer size */
=======
	int count, builtin_result;
	char *cmd = NULL, *prompt = ("($) "), *name, **args = NULL;
>>>>>>> origin/main
	size_t size = 0;
	ssize_t input;
	unsigned int line_count = 0;
	name = (argc > 0 && argv && argv[0] ? argv[0] : "hsh");


	while (1)
=======
	char *line;
	char **args;
	int status = 1;

	/* Set up signal handling */
	signal(SIGINT, SIG_IGN);

	while (status)
>>>>>>> origin/main
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
<<<<<<< HEAD

<<<<<<< HEAD
=======
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
>>>>>>> origin/main
=======
>>>>>>> origin/main
