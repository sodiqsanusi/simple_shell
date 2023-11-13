#include "shell.h"

static unsigned char sig_flag = 1;
/**
* sighandler - handle signals from keyboard interrupts
* @sig: the signal caught
*
* Return: "void" Nothing
*/
static void sighandler(int sig __attribute__((unused)))
{
	sig_flag = 0;
}

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

	if (signal(SIGINT, sighandler) == SIG_ERR)
	{
		perror("signal");
		exit(98);
	}
	while (1)
	{
		first_input = get_line();
		if (sig_flag == 0)
		{
			free(first_input);
			exit(98);
		}
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
			wait(&status);
		free(first_input);
		free_string_arr(words);
	}
	return (0);
}

