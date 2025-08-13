#include "main.h"

/**
 * path_checker - Handle env paths.
 * @argv: Argument values.
 *
 * Return: Void.
 */

void path_checker(char **argv)
{
	int i;
	struct stat st;

	printf("Before stat\n");/* Debug */
	for (i = 0; argv[i]; i++)
	{
		if (stat(argv[i], &st) == 0)
			printf(" Found\n");/* Debug */
		else
			printf(" Not found\n");/* Debug */
	}
}
