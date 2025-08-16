#include "main.h"

/**
 * _strdup - Duplicate a string into a newly allocated memory.
 * @str: String to duplicate.
 *
 * Return: Pointer to the duplicated string on success, NULL on failure.
 */

char *_strdup(char *str)
{
	char *copy;
	size_t len;

	if (!str)
		return (NULL);

	len = strlen(str) + 1;
	copy = malloc(len);
	if (!copy)
		return (NULL);

	memcpy(copy, str, len);
	return (copy);
}
