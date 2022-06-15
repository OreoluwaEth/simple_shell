#include "shell.h"
/**
 * _myexit - check command line to exit shell
 * @line: command line
 * Return: 0 (Success) 1 (Fail)
 **/
int _myexit(char *line)
{
	char *exit_line = "exit";
	int i = 0;
	int len = _strlen(line);

	if (len == 4)
	{
		while (exit_line[i])
		{
			if (exit_line[i] != line[i])
				return (1);
			i++;
		}
		free(line);
		return (0);
	}
	return (1);
}
