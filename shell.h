#ifndef SHELL_H
#define SHELL_H

/* Other Important Headers, Externs and Struct Variables used*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

/*The Function Prototypes Across All Files*/

/* In the "get_input.c" file*/
char *get_line(void);

/* In the "string_utils1.c" file*/
size_t _strlen(const char *s);
int _strncmp(const char *s1, const char *s2, size_t bytes);
char *_strcpy(char *dest, const char *src);
char *_strcat(const char *dest, const char *src);
char *_strtok(char *src, const char *delim);

/* In the "string_utils2.c" file*/
char *_strdup(const char *src);
void just_print(const char *src);

/* In the "split_input.c" file*/
int count_words(const char *str, char *delim);
char **split_strings(const char *str, char *delim);
void free_string_arr(char **);

/* In the "execute_args.c" file*/
int exec(char *pathname, char **program_args, char **envs);

/* In the "confirm_path.c" file*/
char *_getenv(const char *name);
char *get_path_and_clean(const char *alias);

#endif /* SHELL_H */

