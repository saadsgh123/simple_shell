#include "shell.h"
/**
 * _getenvrament- _getenvrament.
 * @val:val
 * @env:env
 * Return: env2
 */
char *_getenvrament(char *val, char **env)
{
	int i = 0;
	char *env2 = NULL;

	if (val == NULL || env == NULL)
	{
		return (NULL);
	}

	while (env[i])
	{
		char *copy = _strdup(env[i]);
		char *copykey = _strtok(copy, "=");

		if (copykey && _strcmp(copykey, val) == 0)
		{
			char *value = _strtok(NULL, "\n");

			if (value)
			{
				env2 = _strdup(value);

				free(copy);
				return (env2);
			}
		}
		free(copy);
		i++;
	}

	return (NULL);
}
