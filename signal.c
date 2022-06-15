#include "shell.h"
/**
 * signal_c - Ignore input signal Ctrl + C
 * @sign: siganal parameter
 **/
void signal_c(int sign)
{
	signal(sign, SIG_IGN);
	write(STDOUT_FILENO, "\n#cisfun$ ", 11);
	signal(SIGINT, signal_c);
}
