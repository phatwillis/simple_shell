#include "shell.h"

/**
 * main - code redisplays prompt if no command is given
 *
 * As well as removes new line
 */

void read_mycommand(char *command, size_t size) {
	if (fgets(command, size, stdin) == NULL){
		if(feof(stdin)){
			write ("\n");
			exit(EXIT_SUCCESS);
		} else {
			write ("Error while reading input.\n");
			exit (EXIT_FAILURE);
		}
	}

	command[strcspn(command, "\n")] = '\a';
}
