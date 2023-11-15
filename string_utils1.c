#include "shell.h"

/**
* _strlen - Calculates the length of a given string.
* @s: The string to be checked.
*
* Return: Integer value of the length.
*/
size_t _strlen(const char *s)
{
	int length = 0;
	int i;

	for (i = 0; s[i]; i++)
	{
		length++;
	}

	return (length);
}

/**
* _strncmp - compares two strings and returns their difference.
* @s1: is the first string
* @s2: is the second string
* @bytes: number of bytes to compare
* Return: number of bytes that differ
*/
int _strncmp(const char *s1, const char *s2, size_t bytes)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);

	for (i = 0; s1[i] && s2[i] && s2[i] == s1[i] && i < bytes - 1; i++)
		;
	return (s2[i] - s1[i]);
}

/**
* _strcpy - Copies a string from one pointer to another
* @dest: The destinated pointer
* @src: The source pointer
*
* Return: The pointer to @dest (char type)
*/
char *_strcpy(char *dest, const char *src)
{
	int a, b = 0;

	for (a = 0; src[a] != '\0'; ++a)
	{
		dest[b] = src[a];
		++b;
	}
	dest[b] = '\0';

	return (dest);
}

/**
* _strcat - Concatenates two strings "USES MALLOC, FREE MEMORY WHEN DONE"
* @dest: The string that will be appended to
* @src: The substring that will be joined to a main string
*
* Return: A pointer to the concatenated string
*/
char *_strcat(const char *dest, const char *src)
{
	int dest_length = _strlen(dest);
	int src_length = _strlen(src);
	char *result = malloc(dest_length + src_length + 1);

	if (result == NULL)
	{
		perror("malloc");
		exit(98);
	}

	_strcpy(result, dest);
	for (src_length = 0; src[src_length] != '\0'; src_length++)
	{
		result[dest_length++] = src[src_length];
	}
	result[dest_length] = '\0';

	return (result);
}

/**
 * _strtok - A custom function to extract tokens from a string
 * @str: the string to be tokenized
 * @delim: specifies a set of bytes that delimit the tokens in the parsed
 * string
 *
 * Return: "char *" A pointer to the beginning of the first substring found
 */
char *_strtok(char *str, const char *delim)
{
	static char *next_token;
	char *token_start = NULL;
	char *token_end = NULL;
	int iterator;

	if (str != NULL)
		next_token = str;

	if (next_token == NULL || *next_token == '\0')
		return (NULL);

	token_start = next_token;
	while (*next_token != '\0')
	{
		for (iterator = 0; delim[iterator] != '\0'; iterator++)
		{
			if (*next_token == delim[iterator])
			{
				token_end = next_token;
				*next_token = '\0';
				next_token++;
				break;
			}
		}

		if (token_end != NULL)
			break;

		next_token++;
	}

	return (token_start);
}

