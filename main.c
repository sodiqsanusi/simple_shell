#include "shell.h"

/**
* main - The entry point for the executable program
*
* Return: Always 0 (successful)
*/
int main(void)
{
	char *first_input;
	char **words = NULL;

	while (1)
	{
		int i = 0;

		first_input = get_line();
		words = split_strings(first_input, "\t ");
		if (words == NULL)
			continue;
		for (i = 0; words[i]; i++)
			printf("%s\n", words[i]);
	}

	free(first_input);
	return (0);
}

