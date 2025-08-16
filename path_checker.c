#include "main.h"

/**
 * path_checker - Check if command exists in PATH.
 * @cmd: Command to check.
 *
 * Return: Full path to command if found, NULL if not found.
 */

char *path_checker(char *cmd)
{
	int i;
	char *path = NULL, *path_copy, *dir, *full_p;
	struct stat st;

	if (!cmd)
		return (NULL);
	if (stat(cmd, &st) == 0 &&
		S_ISREG(st.st_mode) &&
		(st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
		return (_strdup(cmd));
	if (environ)
	{
		for (i = 0; environ[i]; i++)
		{
			if (strncmp(environ[i], "PATH=", 5) == 0)
			{
				path = environ[i] + 5;
				break;
			}
		}
	}
	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_p = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_p)
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(full_p, strlen(dir) + strlen(cmd) + 2, "%s/%s", dir, cmd);
		if (stat(full_p, &st) == 0 &&
				S_ISREG(st.st_mode) &&
				(st.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)))
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
