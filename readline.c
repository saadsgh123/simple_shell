#include "shell.h"
/**
 * readLine - shell helper function.
 * @isInteractive: line read from prompt.
 * Return: 1 if Empty.
 */
char *readLine(int isInteractive)
{
	char *lineptr  = NULL;

	size_t n = 0;
	ssize_t read;

	if (isInteractive)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}

	read = getline(&lineptr, &n, stdin);

	if (read == -1)
	{
		free(lineptr);
	return (NULL);
	}

	if (read > 0 && lineptr[read - 1] == '\n')
	{
		lineptr[read - 1] = '\0';
	}

	return (lineptr);
}
