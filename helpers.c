#include "shell.h"

/**
  * get_path - Get envirnment path
  * Return: environment path
  */
char *get_path(void)
{
	char *path_env, *path_copy;
	int i;

	/* Get PATH environment variable */
	path_env = NULL;
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
	}
	if (path_env == NULL)
		return (NULL);

	/* Copy PATH to avoid modifying original */
	path_copy = strdup(path_env);
	if (path_copy == NULL)
		return (NULL);

	return (path_copy);
}

/**
 * find_path - Finds the full path of a command
 * @command: The command to find
 * Return: Full path to command, or NULL if not found
 */
char *find_path(char *command)
{
	char *path_copy, *dir, *full_path;

	/* If command contains '/', check if it exists */
	if (strchr(command, '/') != NULL)
	{
		if (file_exists(command))
			return (command);
		return (NULL);
	}

	path_copy = get_path();

	/* Search each directory in PATH */
	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		full_path = exec_full_path(command, dir);
		if (full_path != NULL)
		{
			free(path_copy);
			return (full_path);
		}
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * file_exists - Checks if a file exists and is executable
 * @filepath: Path to the file
 * Return: 1 if file exists and is executable, 0 otherwise
 */
int file_exists(char *filepath)
{
	struct stat st;

	if (stat(filepath, &st) == 0)
	{
		if (S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
			return (1);
	}

	return (0);
}

/**
 * exec_full_path - Builds full path and checks if executable exists
 * @command: The command to find
 * @dir: Directory to check
 * Return: Full path if executable exists, NULL otherwise
 */
char *exec_full_path(char *command, char *dir)
{
	char *full_path;

	full_path = malloc(strlen(dir) + strlen(command) + 2);
	if (full_path == NULL)
		return (NULL);

	sprintf(full_path, "%s/%s", dir, command);

	if (file_exists(full_path))
		return (full_path);

	free(full_path);
	return (NULL);
}
