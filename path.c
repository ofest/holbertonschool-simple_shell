char *full_path = search_in_path(argv[0]);
if (full_path == NULL) {
    printf("Error: command not found: %s\n", argv[0]);
    free(argv);
    continue; // Volver al loop sin forkar
}

// Usar full_path en execv()
pid = fork();
if (pid == 0) {
    execv(full_path, argv);
    perror("execv");
    exit(EXIT_FAILURE);
}
free(full_path);
waitpid(pid, &status, 0);


#include <sys/types.h>
#include <sys/stat.h>

struct stat st;

printf("Before stat\n");
for (i = 0; argv[i]; i++)
{
	printf("ici\n");
	if (stat(argv[i], &st) == 0)
		printf(" Found\n");
	else
		printf(" Not found\n");
}
