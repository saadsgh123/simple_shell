#include "shell.h"
/**
 * bultin - bultin.
 * @command: command
 * @argv: argv
 * @env: env
 * @status: status
 * @idx: idx
 */
void bultin(char **command, char **argv, char **env, int *status, int idx)
{
	(void)argv;
	(void)idx;
	if (_strcmp(command[0], "exit") == 0)
	{
		exitshell(command, status);
	}
	else if (_strcmp(command[0], "env") == 0)
	{
		envshell(command, env, status);
	}
}
