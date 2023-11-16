#include "shell.h"
/**
 * _strlen - shell helper function.
 * @str: line read from prompt.
 * Return: 1 if Empty.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
