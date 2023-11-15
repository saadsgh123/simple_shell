#include "shell.h"
/**
 * isbuiltin - shell helper function.
 * @command: line read from prompt.
 * Return: 1 if Empty.
 */
int isbuiltin(char *command)
{
	char *builtinCommands[] = {
		"cd", "pwd", "echo", "exit", "alias", "history", "export",
		"unset", "env", NULL
	};
	for (int i = 0; builtinCommands[i] != NULL; i++)
	{
		if (strcmp(builtinCommands[i], command) == 0)
		{
			return (1);
		}
	}

	return (0);
}
