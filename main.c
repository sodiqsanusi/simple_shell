#include "shell.h"

static int cmd_count = 1;
static int err_status = 1;
/**
* sighandler - Handles the signal from keyboard interrupts.
* @sig: the signal caught.
*
* Return: "void" Nothing.
*/
static void sighandler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n", 1);
}

/**
* handle_error - This is supposed to handle the error printing
* @str: The file not found
*
* Return: "void" Nothing
*/
void handle_error(const char *str)
{
	if (_strncmp(str, "exit", 5) == 0)
	{
		if (cmd_count == 1)
			errno = 0;
		err_status = errno;
		return;
	}
	dprintf(STDERR_FILENO, "./hsh: %d: %s: not found\n", cmd_count, str);
	err_status = 127;
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
		errno = 0;
		words = split_strings(first_input, " \t");
		if (words == NULL)
		{
			free(first_input);
			continue;
		}
		checked_alias = get_path_and_clean(words[0]);
		if (!checked_alias)
		{
			handle_error(words[0]);
			free(first_input);
			free_string_arr(words);
			cmd_count++;
			break;
		}
		free(words[0]);
		words[0] = checked_alias;
		child_pid = fork();
		if (words && child_pid == 0)
			exec(words[0], words, environ);
		else
			wait(&status);
		free(first_input);
		free_string_arr(words);
		cmd_count++;
	}
	return (err_status);
}

