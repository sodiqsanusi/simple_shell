#include "shell.h"

/**
* split_strings - Splits a string, and puts it in an array "USES MALLOC"
* @str: "const char *" The string being splitted
* @delim: "char *" The delimiter to split the string
*
* Return: "char **" An array of strings, with each word splitted
*/
char **split_strings(const char *str, char *delim)
{
	char *base_str = _strdup(str); /* "FREE" */
	int i = 0, alpha = 0;
	int flag = 0;
	char **words = NULL;
	char *token = NULL;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' || str[i] == '\t')
		{
			flag = 0;
			continue;
		}
		if (flag == 1)
			continue;
		alpha++;
		flag = 1;
	}

	if (alpha == 0)
		return (NULL);

	words = malloc((alpha + 1) * sizeof(char *)); /* "FREE" */
	token = _strtok(base_str, delim);
	i = 0;
	while (token)
	{
		if (*token == ' ' || *token == '\t' || *token == '\0')
		{
			token = _strtok(NULL, delim);
			continue;
		}
		words[i] = token;
		i++;
		token = _strtok(NULL, delim);

	}

	words[i] = NULL;
	return (words);
}

