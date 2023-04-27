#include "shell.h"
char *lin = NULL;

/**
 * getLine - function to get line from the prompt
 * @code: the input to get
 * 
 * Return: buffer of the read input
 */
char *getLine(int code)
{
	char *buf = NULL;
	ssize_t read;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Our Shell $ ", 12);
	}

	read = getline(&buf, &n, stdin);
	if (read <= 0)
	{
		freeEnv();
		_exit(code);
	}
	lin[read] = '\0';
	return (buf);
}

