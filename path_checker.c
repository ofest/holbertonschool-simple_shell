#include "main.h"

/**
 * path_checker - Check if command exists in PATH.
 * @cmd: Command to check.
 *
 * Return: Full path to command if found, NULL if not found.
 */

char *path_checker(char *cmd)
{
	char *path, *path_copy, *dir, *full_p;
	struct stat st;

	if (!cmd)
		return (NULL);
	/* If 'cmd' is a valid existing path to an executable, return it */
	if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		return (_strdup(cmd));
	/* Get PATH environment variable */
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	/* Search in each directory of PATH */
	dir = strtok(path_copy, ":");
	while (dir)
	{
		/* Allocate space for full path */
		full_p = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_p)
		{
			free(path_copy);
			return (NULL);
		}
		/* Build full path */
		sprintf(full_p, "%s/%s", dir, cmd);
		/* Check if file exists and is executable */
		if (stat(full_p, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (full_p);
		}
		free(full_p);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
