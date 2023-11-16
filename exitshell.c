#include "shell.h"
/**
 * exitshell - exitshell.
 * @command: command
 * @status: status
 */
void exitshell(char **command, int *status)
{
	int i = 0;

	if (*status == 0)
	{
		*status = 0;
	}
	else
	{
		*status = 2;
	}

	while (command[i] != NULL)
	{
		free(command[i]);
		i++;
	}
	free(command);
	exit(*status);
}
