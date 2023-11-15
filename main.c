#include "shell.h"

/**
* sighandler - handle signals from keyboard interrupts
* @sig: the signal caught
*
* Return: "void" Nothing
*/
static void sighandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
* main - The entry point for the executable program
*
* Return: Always 0 (successful)
*/
int main(void)
{
	char *first_input = NULL, *checked_alias, **words = NULL;
	pid_t child_pid;
	int status;

	signal(SIGINT, sighandler);
	while (1)
	{
		first_input = get_line();
		words = split_strings(first_input, " \t");
		if (words == NULL)
		{
			free(first_input);
			continue;
		}
		checked_alias = get_path_and_clean(words[0]);
		if (!checked_alias)
		{
			perror("file not found");
			free(first_input);
			free_string_arr(words);
			continue;
		}
		free(words[0]);
		words[0] = checked_alias;
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
			wait(&status);
		free(first_input);
		free_string_arr(words);
	}
	return (0);
}

