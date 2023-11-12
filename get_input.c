#include "shell.h"

/**
* get_line - Gets a line of input from the terminal
*
* Return: "char *" The line stream gotten in a string format
*/
char *get_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read;

	printf("$ ");
	bytes_read = getline(&line, &len, stdin);

	if (bytes_read == -1)
	{
		free(line);
		exit(98);
	}

	if (bytes_read > 0 && line[bytes_read - 1] == '\n')
		line[bytes_read - 1] = '\0';

	/*Do not forget to free the "line" memory when done with it*/
	return (line);
}

