#include "shell.h"
/**
 * _strcpy - shell helper function.
 * @dest: line read from prompt.
 * @src: source.
 * Return: 1 if Empty.
 */
char *_strcpy(char *dest, const char *src)
{
	char *originalDest = dest;

	while ((*dest++ = *src++) != '\0')
	{
	}

	return (originalDest);
}
/**
 * _strcat - shell helper function.
 * @dest: line read from prompt.
 * @src: source.
 * Return: 1 if Empty.
 */
char *_strcat(char *dest, const char *src)
{
	size_t dest_len = _strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; ++i)
	{
		dest[dest_len + i] = src[i];
	}

	dest[dest_len + i] = '\0';

	return (dest);
}
/**
 * _strtok - shell helper function.
 * @str: line read from prompt.
 * @delim: source.
 * Return: 1 if Empty.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken;
	char *tokenStart;

	if (str != NULL)
	{
		lastToken = str;
	}
	else if (lastToken == NULL)
	{
		return (NULL);
	}

	while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL)
	{
		lastToken++;
	}

	if (*lastToken == '\0')
	{
		return (NULL);
	}

	tokenStart = lastToken;

	while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL)
	{
		lastToken++;
	}

	if (*lastToken != '\0')
	{
		*lastToken++ = '\0';
	}

	return (tokenStart);
}
/**
 * _strdup - shell helper function.
 * @str: line read from prompt.
 * Return: 1 if Empty.
 */
char *_strdup(const char *str)
{
	size_t len;
	char *copy = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	len = strlen(str) + 1;
	copy = (char *)malloc(len);

	if (copy != NULL)
	{
		_strcpy(copy, str);
	}
	return (copy);
}
/**
 * _strcmp - shell helper function.
 * @str1: line read from prompt.
 * @str2: source.
 * Return: 1 if Empty.
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else if (*str1 < *str2)
	{
		return (-1);
	}
	else
	{
		return (1);
	}
}
