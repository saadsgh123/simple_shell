#include "shell.h"
#include <string.h>

void envshell(char **command, char **env, int *status)
{
	int i = 0, j;
	(void)command;
	(void)status;

	while (env[i])
	{
        	i++;
	}

	qsort(env, i, sizeof(char *), compare_env);

	for (j = i - 1; j >= 0; j--)
	{
		write(STDOUT_FILENO, env[j], strlen(env[j]));
	      	write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
}

int compare_env(const void *a, const void *b)
{
	return strcmp(*(const char **)a, *(const char **)b);
}
