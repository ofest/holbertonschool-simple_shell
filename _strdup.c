#include "main.h"

/**
 * _strdup - string and up
 * @str: strring to duplicate
 *
 * Return: 0
 */

char *_strdup(char *str)
{
	char *cpy;
	unsigned long int i = 0;

	if (str == NULL)
	{
		return (NULL);
	}

	while (str[i] != '\0')
	{
		i++;
	}

	cpy = malloc(i + 1);

	if (cpy == NULL)
	{
		free(cpy);
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; i++)
	{
		cpy[i] = str[i];
	}
	cpy[i] = '\0';

	return (cpy);
	free(cpy);
}
