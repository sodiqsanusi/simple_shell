#include "shell.h"

/**
* main - The entry point for the executable program
*
* Return: Always 0 (successful)
*/
int main(void)
{
	char *first_input = NULL;
	char **words = NULL;
	pid_t child_pid;
	int status;

	while (1)
	{
		first_input = get_line();
		words = split_strings(first_input, " \t");
		if (words == NULL)
		{
			free(first_input);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork");
			free(first_input);
			free_string_arr(words);
			continue;
		}
		if (words && child_pid == 0)
			exec(words[0], words, environ);
		else
		{
			wait(&status);
		}
		free(first_input);
		free_string_arr(words);
	}
	return (0);
}

