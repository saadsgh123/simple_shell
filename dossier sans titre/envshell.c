#include "shell.h"
/**
* envshell - shell helper function.
* @command: line read from prompt.
* @env: environment
* @status: status.
*/
void envshell(char **command, char **env, int *status)
{
	(void)command;
	(void)status;

	int i = 0;

	while (env[i])
	{
		i++;
	}

	qsort(env, i, sizeof(char *), compare_env);

	for (int j = i - 1; j >= 0; j--)
	{
		write(STDOUT_FILENO, env[j], strlen(env[j]));
		write(STDOUT_FILENO, "\n", 1);
	}
	/**
	 * for (int j = 0; j < i; j++) {
     *     write(STDOUT_FILENO, env[j], strlen(env[j]));
     *    write(STDOUT_FILENO, "\n", 1);
     * }
     */
	(*status) = 0;
}
/**
* compare_env - shell helper function.
* @a: line read from prompt.
* @b: environment
* Return: 1 or 0.
*/
int compare_env(const void *a, const void *b)
{
	return (strcmp(*(const char **)a, *(const char **)b));
}
