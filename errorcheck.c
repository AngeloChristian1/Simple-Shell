#include "shell.h"

/**
 * int_string - converts an integer to a string
 * @digits: integer to be converted
 *
 * Return: string representation of the integer
 */
char *int_string(int digits)
{
	int count = 0, i, absMod, digitTest;
	char *output;

	digitTest = digits;
	while (digitTest != 0)
	{
		digitTest /= 10;
		count++;
	}
	output = malloc(sizeof(char) * (count + 1));
	if (output == NULL)
	return (NULL);
	digitTest = digits;
	for (i = count - 1; i >= 0; i--)
	{
	       	absMod = digitTest % 10;
	       	output[i] = absMod + '0';
	       	digitTest /= 10;
	}
	output[count] = '\0';
	return (output);
}

/**
 * checkError - error handling
 * @source: pass in arg 0 from argv in main
 * @command: pass in your tokenized arguments from getline
 * @code: code to specify the error message
 *
 * Return: exit code for shell
 */
int checkError(char *source, char **command, int code)
{
	int atty = isatty(STDIN_FILENO), eCode = 0;
	char *number = NULL;
    
	if (code > 0)
	{
	if (atty == 0 && code != 6 && code != 7)
	{
	       	number = int_string(line);
		write(2, source, _strLen(source)), write(2, ": ", 2);
		write(2, number, _strLen(number)), write(2, ": ", 2);
		free(number);
	}
	}

	if (code == 1)
		write(2, command[0], _strLen(command[0])), write(2, ": not a file or directory\n", 27);
	else if (code == 3)
	{
		write(2, command[0], _strLen(command[0]));
	if (atty == 0)
		write(2, ": not found\n", 13);
	else
		write(2, ": command not found\n", 21);
        eCode = atty == 0 ? 127 : 0;
    }
    else if (code == 4)
        write(2, command[0], _strLen(command[0])), write(2, ": permission denied\n", 21), eCode = 126;
    else if (code == 6)
        write(2, source, _strLen(source)), write(2, ": ", 2), write(2, command[0], _strLen(command[0])),
        write(2, ": too many arguments\n", 22), eCode = 1;
    else if (code == 7)
        write(2, source, _strLen(source)), write(2, ": ", 2), write(2, command[0], _strLen(command[0])),
        write(2, ": ", 2), write(2, command[1], _strLen(command[1])), write(2, ": numeric argument required\n", 29),
        eCode = 128;
    else if (code == 8)
        write(2, command[0], _strLen(command[0])), write(2, ": invalid arguments\n", 21), eCode = 1;

    return (eCode);
}

