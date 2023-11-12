#include "shell.h"

/**
* main - The entry point for the executable program
*
* Return: Always 0 (successful)
*/
int main(void)
{
	char *first_input;

	while (1)
	{
		first_input = get_line();
		printf("%s\n", first_input);
	}

	free(first_input);
	return (0);
}

