#include "main.h"

/**
 * main - Main loop.
 * @argc: Argument count.
 * @argv: Argument values.
 * @envp: Environment pointer.
 *
 * Return: 0 on success, 1 on error
 */

int main(int argc, char **argv, char **envp)
{
	int count;
	char *cmd = NULL, *prompt = ("($) ");
	size_t size = 0;
	ssize_t read_chars;
	int interactive = isatty(STDIN_FILENO);

	(void)argc;

	while (1)
	{
		if (interactive)
			printf("%s", prompt);
		read_chars = getline(&cmd, &size, stdin);
		if (read_chars == -1)
		{
			printf("\n");
			free(cmd);
			return (0);
		}
		if (cmd[read_chars - 1] == '\n')
			cmd[read_chars - 1] = '\0';
		if (strlen(cmd) == 0)
			continue;
		count = arg_counter(cmd);
		if (count <= 0)
			continue;
		argv = arg_filler(count, cmd);
		if (!argv)
			continue;
		if (handle_builtins(argv, envp) == 1)
			continue;
		else if (handle_builtins(argv, envp) == 2)
			return (0);
		if (execute_command(argv) == -1)
			fprintf(stderr, "hsh: command not found: %s\n", argv[0]);
		free(argv);
	}
	free(cmd);
	return (0);
}
