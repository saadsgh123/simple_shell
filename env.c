#include "shell.h"
/**
 * _getenvrament - shell helper function.
 * @val: line read from prompt.
 * @env: environment variable.
 * Return: 1 if Empty.
 */
char *_getenvrament(char *val, char **env)
{
	if (val == NULL || env == NULL)
	{
		return (NULL);
	}
	int i = 0;

	while (env[i])
	{
	char *copy = _strdup(env[i]);
	char *copykey = _strtok(copy, "=");

	if (copykey && strcmp(copykey, val) == 0)
	{
		char *value = _strtok(NULL, "\n");

		if (value)
		{
			char *env2 = _strdup(value);

			free(copy);
			return (env2);
		}
	}
	free(copy);
	i++;
	}

	return (NULL);
}
