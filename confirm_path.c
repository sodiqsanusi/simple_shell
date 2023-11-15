#include "shell.h"

/**
* _getenv - A function mirroring the normal "getenv" system call.
* @name: "const char *" The name of the environment variable being searched.
*
* Return: "char *" The information of the environmental variable.
*/
char *_getenv(const char *name)
{
	int i;
	char *match = NULL;
	int name_length = _strlen(name);

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(name, environ[i], name_length) == 0)
		{
			match = environ[i];
			break;
		}
	}

	return (match);
}

/**
* set_it_right - Puts the pointer to be after the "=" "USES MALLOC!!!"
* @name: "char *" The direct environmental variable.
*
* Return: "char *" The string after the "="
*/
char *set_it_right(char *name)
{
	char *env = _getenv(name);
	char *temp_data = _strdup(env); /* "FREE" */
	char *result;
	char *token = _strtok(temp_data, "=");

	while (token)
	{
		result = token;
		token = _strtok(NULL, "=");
	}
	token = result;
	result = _strdup(token); /* "FREE" */
	free(temp_data);

	return (result);
}

/**
* get_path_and_clean - Gets the "PATH" variable and makes it splittable.
* @alias: "char *" The first argument to the terminal.
*
* Return: "int" 0 if alias/file exists,or 1 otherwise.
*/
char *get_path_and_clean(const char *alias)
{
	char *jumbled_paths, *result = NULL;
	char **path_arr;
	int i;
	struct stat file_info;

	if (stat(alias, &file_info) == 0)
	{
		result = _strdup(alias);
		return (result);
	}
	jumbled_paths = set_it_right("PATH"); /* "FREE"*/
	path_arr = split_strings(jumbled_paths, ":"); /* "FREE"*/

	for (i = 0; path_arr[i]; i++)
	{
		char *temp = _strcat(path_arr[i], "/"); /* "FREE" */
		char *fullpath = _strcat(temp, alias);

		free(temp);
		if (stat(fullpath, &file_info) == 0)
		{
			result = _strdup(fullpath);
			free(fullpath);
			break;
		}
		free(fullpath);
	}
	free_string_arr(path_arr);
	free(jumbled_paths);

	return (result);
}

