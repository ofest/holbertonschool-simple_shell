#include "main.h"

/**
 * arg_counter - Count argument number of the command.
 * @cmd: Command to count.
 *
 * Return: Number of command arguments, 0 on error.
 */

int arg_counter(char *cmd)
{
	int count;
	char *tmp_cmd, *token;

	if (!cmd || strlen(cmd) == 0)
		return (0);

	tmp_cmd = _strdup(cmd);
	if (!tmp_cmd)
		return (0);

	token = strtok(tmp_cmd, " \n");
	for (count = 0; token; count++)
		token = strtok(NULL, " \n");

	free(tmp_cmd);
	return (count);
}
