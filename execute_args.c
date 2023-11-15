#include "shell.h"

/**
* exec - A function to practice the "execve" system call
* @pathname: The pathname to the binary executable to be run
* @program_args: An array of arguments to the executable file, pathname is [0]
* @envs: Environmental variables the program is supposed to run in
*
* Return: 0 if successful, -1 otherwise
*/
int exec(char *pathname, char **program_args, char **envs)
{
	int lilac;

	lilac = execve(pathname, program_args, envs);
	if (lilac == -1)
	{
		perror("exec");
		exit(91);
	}

	return (0);
}

