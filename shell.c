#include "shell.h"
/**
 * main -Entry point
 * @argc: argc
 * @argv: argv
 * @env: env
 * Return: 0.
 */
int main(int argc, char **argv, char **env)
{
	int idx = 0, isEmpty = 0, status = 0;
	char *line = NULL;
	char **command = NULL;
	int isInteractive = isatty(STDIN_FILENO);

	(void)argc;
	while (1)
	{
		line = readLine(isInteractive);
		if (line == NULL)
		{
			if (isInteractive)
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
			return (status);
		}

		isEmpty = checkIfLineIsEmpty(line);

		if (isEmpty)
		{
			free(line);
			continue;
		}

		idx++;

		command = tokenizeInput(line);

		if (command != NULL)
		{
			processCmd(command, argv, env, &status, idx);
			freeCommand(command);
		}
		free(line);
	}

	return (status);
}
/**
 * checkIfLineIsEmpty - function checks if line input is Empty
 * @line: line
 * Return: 1 if true.
 */
int checkIfLineIsEmpty(char *line)
{
	int i;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			return (0);
		}
	}
	return (1);
}
/**
 * processCmd - processCmd.
 * @command: command
 * @argv: argv
 * @env: env
 * @status: status
 * @idx: idx
 */
void processCmd(char **command, char **argv, char **env, int *status, int idx)
{
	int i;

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
}
/**
 * freeCommand - function that frees memory.
 * @command: command
 */
void freeCommand(char **command)
{
	int i;

	for (i = 0; command[i] != NULL; i++)
	{
		free(command[i]);
	}

	free(command);
}
