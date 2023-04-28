#include "shell.h"

/**
* getLine - Reads a line of input from the standard input and
* returns it as a character pointer.
*
* @code: Exit code to use if an error occurs.
*
* Return: A pointer to the line of input read from the standard input,
* or NULL if an error occurred.
*
* This function reads a line of input from the standard input using
* the getline function. If the input line is empty or could not be read
* successfully, this function frees any allocated memory and exits the
* program with the specified exit code.
*/
char *getLine(int code)
{
char *line = NULL;
ssize_t read;
size_t len = 0;

if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "#OG Shell$ ", 11);

read = getline(&line, &len, stdin);

if (read <= 0)
{
freeEnv();
_exit(code);
}

line[read - 1] = '\0'; /* remove the newline character from the end */

return (line);
}

