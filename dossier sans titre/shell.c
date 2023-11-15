#include "shell.h"
/**
* processCommand - shell command processor.
* @cmd: arguments count.
* @argv: list of arguments
* @env: environment variable.
* @status: status
* @idx: pip index
*/
void processCommand(char **cmd, char **argv, char **env, int *status, int idx)
{
	int i;

	if (cmd != NULL)
	{
		for (i = 0; cmd[i] != NULL; i++)
		{
			if (strcmp(cmd[i], "") != 0)
			{
			}
		}

		if (isbuiltin(cmd[0]))
		{
			bultin(cmd, argv, env, status, idx);
		}
		else
		{
			*status = _execute(cmd, env, argv, idx);
		}

		for (i = 0; cmd[i] != NULL; i++)
		{
			free(cmd[i]);
		}
		free(cmd);
	}
}
/**
 * processInput - shell command processor.
 * @status: arguments count.
 * @argv: list of arguments
 * @env: environment variable.
 */
void processInput(int *status, char **argv, char **env)
{
	int idx = 0, isEmpty = 1, i;
	char *line = NULL;
	int isInteractive = isatty(STDIN_FILENO);

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
		return;
		}
		for (i = 0; line[i] != '\0'; i++)
		{
			if (line[i] != ' ' && line[i] != '\t')
			{
				isEmpty = 0;
				break;
			}
		}
		if (isEmpty)
		{
			free(line);
			continue;
		}
		idx++;

		char **command = tokenizeInput(line);

		free(line);
		processCommand(command, argv, env, status, idx);
	}
}
/**
 * main - Entry point.
 * @argc: arguments count.
 * @argv: list of arguments
 * @env: environment variable.
 * Return: 0.
 */
int main(int argc, char **argv, char **env)
{
	int status = 0;

	(void)argc;

	processInput(&status, argv, env);

	return (status);
}
