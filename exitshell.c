#include "shell.h"
/**
 * exitshell - shell command processor.
 * @command: arguments count.
 * @env: environment variable.
 * @status: pip index.
 */
void exitshell(char **command, char **env, int *status)
{
	(void) env;
	if (*status == 0)
	{
		*status = 0;
	}
	else
	{
		*status = 2;
	}
	int i = 0;

	while (command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	free(command);
	exit(*status);
}
