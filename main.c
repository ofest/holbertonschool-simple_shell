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
	char *cmd = NULL, char *prompt = ("($) "), char *program_name = "hsh";
	size_t size = 0;
	ssize_t input;
	(void)argc, (void)argv;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("%s", prompt);
		input = getline(&cmd, &size, stdin);
		if (input == -1 || !cmd || size < 2)
			break;
		if (cmd[input - 1] == '\n')
			cmd[input - 1] = '\0';
		if (strlen(cmd) == 0)
			continue;
		count = arg_counter(cmd);
		if (count <= 0)
			continue;
		argv = arg_filler(count, cmd);
		if (!argv)
			continue;
		builtin_result = handle_builtins(argv, envp);
		if (builtin_result == 1)
		{
			free(argv);
			continue;
		}
		else if (builtin_result == 2)
		{
			free(argv);
			free(cmd);
			return (0);
		}
		if (execute_command(argv, envp) == -1)
			fprintf(stderr, "%s: 1: %s: not found\n", program_name, argv[0]);
		free(argv);
	}
	free(cmd);
	return (0);
}
