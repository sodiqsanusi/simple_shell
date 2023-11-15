#include "shell.h"

/**
* _strdup - Duplicates a string "USES MALLOC, FREE MEMORY SPACE WHEN DONE"
* @src: source to copy from
*
* Return: pointer to malloc'd space
*/
char *_strdup(const char *src)
{
	int len, i;
	char *dest;

	if (src == NULL)
		return (NULL);
	len = _strlen(src);
	if (len < 0)
		return (NULL);
	len++;

	dest = malloc((len) * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dest[i] = src[i];
	dest[i - 1] = '\0';
	return (dest);
}

/**
* just_print - A simpler recreation of the "printf" function
* @src: "const char *" The string to be printed
*
* Return: "void" Nothing
*/
void just_print(const char *src)
{
	int len;

	len = _strlen(src);
	write(STDOUT_FILENO, src, len);
}

