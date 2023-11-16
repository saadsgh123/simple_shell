#include "shell.h"
/**
 * intToA - shell helper function.
 * @num: line read from prompt.
 * Return: 1 if Empty.
 */
char *intToA(int num)
{
	int temp = num, i, start = 0, end = 0;
	char *str = NULL;
	int numDigits = 1;

	while (temp >= 10)
	{
		temp /= 10;
		numDigits++;
	}

	str = (char *)malloc(numDigits + 1);

	if (str == NULL)
		return (NULL);
	str[numDigits] = '\0';

	for (i = numDigits - 1; i >= 0; i--)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}


	end = numDigits - 1;

	while (start < end)
	{
		char temp = str[start];

		str[start] = str[end];

		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}
