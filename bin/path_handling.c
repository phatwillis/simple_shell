#include "shell.h"

/**
 * main - process path for both pid and ppid
 *
 * Description: tokenize path into individual directories and
 * input into commands and arguments.
 *
 * Returns: 0 on Sucess
 *
 */

void execute_command(char *args[])
{
	pid_t pid = fork();

	if (pid == 0)
	{

		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			_exit(EXIT_FAILURE);
		}
	} else if (pid < 0)
	{

		perror("Error");
	} else
	{

		wait(NULL);
	}
}

int is_command_in_path(char *command, char *path_dirs[])
{
	while (*path_dirs != NULL)
	{
		char command_path[MAX_PATH_SIZE];

		snprintf(command_path,
		sizeof(command_path), "%s/%s", *path_dirs, command);

		if (access(command_path, X_OK) == 0)
		{
			return (1);
		}

		path_dirs++;
	}

	return (0);
}

int main(void)
{
	char input[MAX_INPUT_SIZE];
	char *path = getenv("PATH");

	if (path == NULL)
	{
		write(STDERR_FILENO, "Error\n", 40);
		return (EXIT_FAILURE);
	}


	char *path_dirs[MAX_PATH_SIZE];
	char *path_token = strtok(path, ":");

	int i = 0;

	while (path_token != NULL && i < MAX_PATH_SIZE - 1)
	{
		path_dirs[i++] = path_token;
		path_token = strtok(NULL, ":");
	}
	path_dirs[i] = NULL;

	for (write(STDOUT_FILENO, ":) ", 3);
			fgets(input, sizeof(input), stdin)
	!= NULL; write(STDOUT_FILENO, ":) ", 3))
	{

		input[strcspn(input, "\n")] = 0;

		char *token = strtok(input, " ");
		char *args[MAX_INPUT_SIZE];
		int j = 0;

		while (token != NULL && j < MAX_INPUT_SIZE - 1)
		{
			args[j++] = token;
			token = strtok(NULL, " ");
		}
		args[j] = NULL;


		if (is_command_in_path(args[0], path_dirs))
		{

			execute_command(args);
		} else
		{
			write(STDERR_FILENO, "Error: Command not found\n", 25);
		}
	}

	return (0);
}
