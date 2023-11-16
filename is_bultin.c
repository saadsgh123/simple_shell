#include "shell.h"
/**
 * isbuiltin - isbuiltin.
 * @command: command
 * Return: 0;
 */
int isbuiltin(char *command)
{
	int i;
	char *builtinCommands[] = {
		"cd", "pwd", "echo", "exit", "alias", "history", "export",
		"unset", "env", NULL
	};

	for (i = 0; builtinCommands[i] != NULL; i++)
	{
		if (_strcmp(builtinCommands[i], command) == 0)
		{
			return (1);
		}
	}

	return (0);
}
