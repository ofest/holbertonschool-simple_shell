#include "main.h"

/**
 * arg_counter - Count argument number of the command.
 * @cmd: Command to count.
 *
 * Return: Number of command arguments.
 */

int arg_counter(char *cmd)
{
	int count;
	char *tmp_cmd, *token;

	tmp_cmd = strdup(cmd);
	if (!tmp_cmd)
		return (0);

	token = strtok(tmp_cmd, " \n");
	for (count = 0; token;)
	{
		count++;
		token = strtok(NULL, " \n");
	}
	printf("Arg number : %i\n", count); /* Debug */
	free(tmp_cmd);
	return (count);
}
