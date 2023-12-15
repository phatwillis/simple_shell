#ifndef SHELL_H
#define SHELL_H

/* Includes Header Files */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stddef.h>
#include <errno.h>
#include <stdbool.h>
#include <sys/stat.h>

/* STRUCTURE  */

/**
 * struct Node_env - structure that handles the env
 * @data: the env list
 * @number: to check the env list
 * @next: pointer to the next node
 */

typedef struct Node_env
{
	char *data;
	int number;
	struct Node_env *next;
} Node_env;

/* Functions Protoype */

void handle_signal(int sig);
void prompt(void);
int count_Args(const char *cmd);
char **split_string(const char *cmd);
void execute_cmd(const char *cmd, char *const envp[]);
void free_new_av(char **new_av);
char *_getenv(const char *str);
char *handel_path(const char *cmd);
int print_error(char *str);
void _perror(const char *cmd, char *error_message);
void _exit_builtin(char *cmd, char *status);
Node_env *create_node(char *data, int number);
void add_to_list(Node_env **head, Node_env *new_node);
void print_env(Node_env *head);
int handle_env(void);
void free_env(Node_env *head);
char *_strtok(char *str, const char *delim);
int _atoi(char *str);
int w_count(char *av, char ***args);
void free_environ(char **env);
int _change_dir(char *cmd);
int word_count(char *str, char *delim);
char *_handle_comment(char *cmd);

/* The String Function Prototype*/

int _strcmp(const char *str1, const char *str2);
int _strlen(const char *str);
size_t _strcspn(const char *str, const char *charset);
char *_strdup(char *str);
void *_memcpy(void *dest, const void *src, size_t n);
size_t _strspn(const char *str, const char *charset);
char *_strchr(const char *str, int character);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcpy(char *to, const char *from);
char *_strcat(char *to, const char *from);

/* MACROS */

static char *cmd __attribute__((unused));
extern char **environ;
#define MAX_PATH_LENGTH 1024
#define MAX_ARGS 64
extern int updated;

#endif /* SHELL_H */
