#include "shell.h"
/**
 * _execute - shell command processor.
 * @cmd: arguments count.
 * @argv: list of arguments
 * @env: environment variable.
 * @idx: pip index.
 * Return: 0
 */
int _execute(char **cmd, char **env, char **argv, int idx)
{
	char *fullcmd = NULL;
	pid_t child;

	fullcmd = Hnadlepath(cmd[0], env);

	if (fullcmd == NULL)
	{
		printerror(argv[0], cmd[0], idx);
		return (127);
	}

	child = fork();
	if (child == -1)
	{
		perror("fork");
		free(fullcmd);
		return (-1);
	}
	if (child == 0)
	{
		free(fullcmd);
		if (execve(fullcmd, cmd, env) == -1)
		{
			printerror(argv[0], cmd[0], idx);
			exit(127);
		}
	}
	else
	{
	int status;

	wait(&status);
	free(fullcmd);
	return (status);
	}
	return (0);
}
