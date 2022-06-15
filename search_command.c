#include "shell.h"
/**
 * execute_process - execute process function
 * @argm: arguments from command_line
 * @argv: string of arguments
 * @counter: number of ecution processes
 * Return: 0 (Success) -1 (Failed)
 **/
int execute_process(char **argm, char **argv, int counter)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buffer = NULL, *command_path = NULL;

	command_path = check_path(argm[0]);
	if (command_path == NULL)
	{
		buffer = execute_command(argm[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: not found\n", argv[0], counter, argm[0]);
			free(buffer);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, argm, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buffer);

	return (status_output);
}
