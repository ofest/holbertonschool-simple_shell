#include "main.h"

/**
 * _strdup - string and up
 * @str: strring to duplicate
 *
 * Return: 0
 */

char *_strdup(char *str)
{
	char *copy;
	unsigned long int i = 0;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
		i++;

	copy = malloc(i + 1);

	if (copy == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		copy[i] = str[i];
	copy[i] = '\0';

	return (copy);
}
