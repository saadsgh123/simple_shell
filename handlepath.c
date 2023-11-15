#include "shell.h"
/**
 * checkInDirectory - Check if the given command exists in the specified dir.
 * @cmd: command line
 * @directory: specified dir.
 * Return: the full path if found, otherwise return NULL.
 */
char *checkInDirectory(char *cmd, char *directory)
{
	int modifiedSize = _strlen(directory) + _strlen(cmd) + 2;
	char *fullcmd = (char *)malloc(modifiedSize);

	if (fullcmd)
	{
		_strcpy(fullcmd, directory);
		_strcat(fullcmd, "/");
		_strcat(fullcmd, cmd);
		struct stat st;

		if (stat(fullcmd, &st) == 0)
		{
			return (fullcmd);
		}
		free(fullcmd);
	}

	return (NULL);
}

/**
 * Hnadlepath - shell command processor.
 * @cmd: command to search for.
 * @env: environment variable.
 * Return: path or NULL if not found.
 */
char *Hnadlepath(char *cmd, char **env)
{
	int i = 0;
	struct stat st;

	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
		}
	i++;
	}

	char *path = _getenvrament("PATH", env);

	if (path == NULL || *path == '\0')
	{
		free(path);
		return (NULL);
	}

	char *directory = _strtok(path, ":");
	char *fullcmd = NULL;

	while (directory)
	{
		fullcmd = checkInDirectory(cmd, directory);

		if (fullcmd != NULL)
		{
			free(path);
			return (fullcmd);
		}

		directory = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
