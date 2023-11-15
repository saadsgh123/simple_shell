#include "shell.h"
/**
 * bultin - shell helper function.
 * @command: line read from prompt.
 * @argv: list of arguments.
 * @env: environment argument.
 * @status: status.
 * @idx: index.
 * Return: 1 if Empty.
 */
void bultin(char **command, char **argv, char **env, int *status, int idx)
{
	(void) argv;
	(void) idx;
	if (_strcmp(command[0], "exit") == 0)
	{
		exitshell(command, env, status);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		envshell(env, env, status);
	}
}
