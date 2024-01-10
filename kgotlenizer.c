#include "shell.h"

/**
 * **strtow - splits string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	int j, k, y, h, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (j = 0; str[j] != '\0'; j++)
		if (!is_delim(str[j], d) && (is_delim(str[j + 1], d) || !str[j + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (is_delim(str[j], d))
			j++;
		y = 0;
		while (!is_delim(str[j + y], d) && str[j + y])
			y++;
		s[k] = malloc((y + 1) * sizeof(char));
		if (!s[k])
		{
			for (y = 0; y < k; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (h = 0; h < y; h++)
			s[k][h] = str[j++];
		s[k][h] = 0;
	}
	s[k] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: input string
 * @d: delimeter
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int j, k, y, h, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (j = 0; str[j] != '\0'; j++)
		if ((str[j] != d && str[j + 1] == d) ||
		    (str[j] != d && !str[j + 1]) || str[j + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0, k = 0; k < numwords; k++)
	{
		while (str[j] == d && str[j] != d)
			j++;
		y = 0;
		while (str[j + y] != d && str[j + y] && str[j + y] != d)
			y++;
		s[k] = malloc((y + 1) * sizeof(char));
		if (!s[k])
		{
			for (y = 0; y < k; y++)
				free(s[y]);
			free(s);
			return (NULL);
		}
		for (h = 0; h < y; h++)
			s[k][y] = str[j++];
		s[k][h] = 0;
	}
	s[k] = NULL;
	return (s);
}
