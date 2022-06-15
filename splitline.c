#include "shell.h"
/**
* splitline - get line command line from the prompt
* @command_line: command line string.
* Return: a pointer to string of command strings.
**/
char **splitline(char *command_line)
{
	char **ptrstr;
	int size = 100;
	int position = 0;
	char *word;

	ptrstr = malloc(sizeof(char *) * size);
	if (ptrstr == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(command_line, " ");
	while (word != NULL)
	{
		ptrstr[position++] = word;
		word = _strtok(NULL, " ");
	}
	ptrstr[position] = NULL;
	return (ptrstr);
}
