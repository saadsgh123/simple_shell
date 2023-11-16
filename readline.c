#include "shell.h"
/**
 * readLine - readLine.
 * @isInteractive: 1 if interactive 0 if not
 * Return: line.
 */
char *readLine(int isInteractive)
{
	char *lineptr  = NULL;

	size_t n = 0;

	ssize_t read;

	if (isInteractive)
	{
		printf("$");
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
