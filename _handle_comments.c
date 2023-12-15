#include "shell.h"

/**
 *  _handle_comment -  the function prevents execution of words after comment
 *  @cmd: it is the command received from stdin
 *
 *  Return: pointer to executable command
 */

char *_handle_comment(char *cmd)
{
	char check[3];
	int i;

	check[2] = '\0';

	if (_strlen(cmd) == 1 && cmd[0] != '#')
		return (cmd);

	if (cmd[0] == '#')
		return (NULL);

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (cmd[i] == '#')
		{
			check[0] = cmd[i - 1];
			check[1] = cmd[i];
			if (_strcmp(check, " #") == 0)
			{
				return (strtok(cmd, "#"));
			}
		}
	}

	return (cmd);
}
