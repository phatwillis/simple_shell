#include "shell.h"

/**
 * Main - Interactive shell that continuously
 * prompts for and executes commands.
 *
 * Description: Run the program to enter the shell.
 * Type commands to execute.
 *
 * Return: 0 on Success
 */

int main(void)
{
	char my_command[115];

	do {
		looping_display_prompt();
		read_mycommand(command, sizeof(command));
		execute_command(command);
	} while (1);

	return (0);
}
