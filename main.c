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
	int count, builtin_result;
	char *cmd = NULL, *prompt = ("($) "), *name, **args = NULL;
	size_t size = 0;
	ssize_t input;
	unsigned int line_count = 0;
	name = (argc > 0 && argv && argv[0] ? argv[0] : "hsh");

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);
		input = getline(&cmd, &size, stdin);
		if (input == -1 || !cmd || size < 2)
		{
			if (isatty(STDIN_FILENO))
				putchar('\n');
			break;
		}
		if (cmd && input > 0 && cmd[input - 1] == '\n')
			cmd[input - 1] = '\0';
		if (!cmd || cmd[0] == '\0')
			continue;
		line_count++;
		count = arg_counter(cmd);
		if (count <= 0)
			continue;
		args = arg_filler(count, cmd);
		if (!args)
			continue;
		builtin_result = handle_builtins(args, envp);
		if (builtin_result == 1)
		{
			free_argv(args);
			continue;
		}
		else if (builtin_result == 2)
		{
			free_argv(args);
			free(cmd);
			return (0);
		}
		if (execute_command(args, envp) == -1)
			fprintf(stderr, "%s: %u: %s: not found\n", name, line_count, args[0]);
		free(args);
	}
	free(cmd);
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
