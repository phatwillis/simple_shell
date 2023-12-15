#include "shell.h"

/**
 * _strtok - This is acustom made strtok function
 * @str: the string to be tokenized
 * @delimiter: the delimters to watch out for
 * Return: the tonkenized string into an array
 */

char *_strtok(char *str, const char *delimiter)
{
	/* variable dose'nt change */
	static char *buffer;
	char *token;
	int i = 0, j = 0, is_found; /* length = _strlen(delimiter); */

	if (str)
	buffer = str;
	if (buffer == NULL || *buffer == '\0')
		return (NULL);
	token = buffer;
	while (buffer[i] != '\0')
	{
		is_found = 0;
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (buffer[i] == delimiter[j])
			{
				is_found = 1;
				break;
			}
		}
		if (is_found)
		{
			buffer[i] = '\0';
			buffer = buffer + i + 1;
			return (token);
		}
		i++;
	}
	buffer = NULL;
	return (token);
}
