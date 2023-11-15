#include "shell.h"
/**
 * main - Entry point.
 * @argc: arguments count.
 * @argv: list of arguments
 * @env: environment variable.
 * Return: 0.
 */
int main1(int argc, char **argv, char **env)
{
	int status = 0, isEmpty, i, idx = 0;
	char *line = NULL;
	(void)argc;
	char **command = NULL;

	while (1)
	{
		line = readLine(isatty(STDIN_FILENO));

		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
				break;
			}
		return (status);
		}

		isEmpty = shell_helper(line);

		if (isEmpty)
		{
			free(line);
			continue;
		}
		idx++;
		command = tokenizeInput(line);

		free(line);
		if (command != NULL)
		{
			processCommand(command, argv, env, &status, idx);

		for (i = 0; command[i] != NULL; i++)
			free(command[i]);
		free(command);
		}
	}
	return (status);
}
/**
 * shell_helper - shell helper function.
 * @line: line read from prompt.
 * Return: 1 if Empty.
 */
int shell_helper(char *line)
{
	int i, isEmpty = 1;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] != ' ' && line[i] != '\t')
		{
			isEmpty = 0;
			break;
		}
	}
	return (isEmpty);
}
/**
 * processCommand - shell command processor.
 * @cmd: arguments count.
 * @argv: list of arguments
 * @env: environment variable.
 * @sts: environment variable.
 * @idx: pip index.
 */
void processCommand(char **cmd, char **argv, char **env, int *sts, int idx)
{
	int j;

	for (j = 0; cmd[j] != NULL; j++)
	{
		if (_strcmp(cmd[j], "") != 0)
		{
            return;
		}
	}
	if (isbuiltin(cmd[0]))
	{
		bultin(cmd, argv, env, sts, idx);
	}
	else
	{
		*sts = _execute(cmd, env, argv, idx);
	}
}