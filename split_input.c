#include "shell.h"

/**
* count_words - Gets the count of words in a string
* @str: "const char *" The string to get the count of
* @delim: "char *" Delimiters
*
* Return: "int" The amount of words present in the string
*/
int count_words(const char *str, char *delim)
{
	int i = 0, alpha = 0;
	int flag = 0;

	for (i = 0; str[i]; i++)
	{
		int j = 0;

		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				flag = 0;
				continue;
			}
		}
		if (flag == 1)
			continue;
		alpha++;
		flag = 1;
	}

	return (alpha);
}

/**
* split_strings - Splits a string, and puts it in an array "USES MALLOC"
* @str: "const char *" The string being splitted
* @delim: "char *" The delimiter to split the string
*
* Return: "char **" An array of strings, with each word splitted
*/
char **split_strings(const char *str, char *delim)
{
	int alpha = 0, i;
	char **words = NULL;
	char *token = NULL, *base_str = NULL;

	alpha = count_words(str, delim);
	if (alpha == 0)
		return (NULL);

	base_str = _strdup(str); /* "FREE" */
	words = malloc((alpha + 1) * sizeof(char *)); /* "FREE" */
	token = _strtok(base_str, delim);
	i = 0;
	while (token)
	{
		char *one_word = NULL;

		if (*token == ' ' || *token == '\t' || *token == '\0')
		{
			token = _strtok(NULL, delim);
			continue;
		}
		one_word = _strdup(token); /* "FREE" */
		words[i] = one_word;
		i++;
		token = _strtok(NULL, delim);

	}

	free(base_str);
	words[i] = NULL;
	if (!words[0])
	{
		free_string_arr(words);
		return (NULL);
	}
	return (words);
}

/**
* free_string_arr - Free the memory allocated to a string array
* @str_arr: The array of string, both array and individual strings on the heap
*
* Return: "void" Nothing
*/
void free_string_arr(char **str_arr)
{
	int i;

	for (i = 0; str_arr[i]; i++)
	{
		free(str_arr[i]);
	}
	free(str_arr);
}
