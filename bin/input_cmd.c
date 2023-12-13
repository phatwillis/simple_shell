#include "shell.h"

/**
 * main - code re-displays prompt if no command is given
 *As well as removes new line
 *
 * Description: code acccepts input
 * and display prompt if no commands is inputted
 *
 * @read_mycommand - reads characters inputed
 *
 * @size: gets size
 * @command: gets commands
 */

void read_mycommand(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			write("\n");
			exit(EXIT_SUCCESS);
		} else
		{
			write("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\a';
}
