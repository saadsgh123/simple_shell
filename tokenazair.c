#include "shell.h"
/**
 * tokenizeInput - tokenizeInput
 * @line: line
 * Return: line.
 */
char **tokenizeInput(char *line)
{
	int counter = 0;

	char *copystring = _strdup(line);

	char *token = _strtok(copystring, " \t\n");

	char **tokenList = NULL;

	while (token)
	{
		tokenList = realloc(tokenList, (counter + 1) * sizeof(char *));
		tokenList[counter++] = strdup(token);
		token = _strtok(NULL, " \t\n");
	}

	tokenList = realloc(tokenList, (counter + 1) * sizeof(char *));
	tokenList[counter] = NULL;

	free(copystring);

	return (tokenList);
}
