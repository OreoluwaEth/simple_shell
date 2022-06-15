#include "shell.h"
/**
 * _getline - get line command line from the prompt
 * @bufline: command buffer line string.
 * @size: size of the command buffer lines.
 * @std: file stream where comes the command buffer line.
 * Return: number of bytes copied in the buffer.
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufline || !size || !std)
		return (-1);
	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
			return (-1);
	}
	while ((c = _getchar()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
