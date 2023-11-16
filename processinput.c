#include "shell.h"
/**
 * processInput - processInput
 * @status: status
 * @argv: status
 * @env: status.
 */
void processInput(int *status, char **argv, char **env)
{
	int idx = 0, isEmpty = 1, i;
	char *line = NULL;
	char **command = NULL;
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

	command = tokenizeInput(line);

	free(line);
	processCmd(command, argv, env, status, idx);
	}
}
