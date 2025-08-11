#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * non_interactive_loop - runs the shell in non-interactive (pipe) mode
 */

void non_interactive_loop(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, stdin)) != -1)
	{
	   
		if (read > 0 && line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		execute_command(line);
	}

	free(line);
}
