#include "shell.h"
/**
 * processCmd - processCommand
 * @command: command
 * @argv: argv
 * @env: env
 * @status: status
 * @idx: idx.
 */
void processCmd(char **command, char **argv, char **env, int *status, int idx)
{
	int i, j;

	if (command != NULL)
	{
		for (i = 0; command[i] != NULL; i++)
		{
			if (_strcmp(command[i], "") != 0)
			{
			}
		}
	if (isbuiltin(command[0]))
	{
		bultin(command, argv, env, status, idx);
	}
	else
	{
		*status = _execute(command, env, argv, idx);
	}
	for (j = 0; command[j] != NULL; j++)
	{
		free(command[j]);
	}
	free(command);
	}
}
/**
 * main - Entry point.
 * @argc: argc
 * @argv: argv
 * @env: env
 * Return: 0.
 */
int main(int argc, char **argv, char **env)
{
	int status = 0;

	(void)argc;

	processInput(&status, argv, env);

	return (status);
}
