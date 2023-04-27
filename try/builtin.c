#include "shell.h"

 * isNumber - checks if a string is a number
 * @s: string to check
 *
 * Return: 1 on success or 0
 */
int isNumber(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _atoi - changes a string to an integer
 * @s: string to convert
 *
 * Return: num on success
 */
int _atoi(char *s)
{
	int i = 0, np = 0, c = 0, d = 1, num = 0;

	while (i < _strLen(s))
	{
		if (s[i] >= '0' && s[i] <= '9')
			c++;
		if (s[i] == '+')
			np++;
		if (s[i] == '-')
			np--;
		if (!(s[i] >= '0' && s[i] <= '9') && c > 0)
			break;
		i++;
	}
	while (c > 0)
	{
		num += ((s[i - 1] - '0') * d);
		i--;
		c--;
		d *= 10;
	}
	if (np >= 0)
		num *= 1;
	else
		num *= -1;
	return (num);
}

/**
 * exit_shell - exits the shell
 * @argv: argument vector
 * @code: exit code
 *
 * Return: void
 */
void exit_shell(char **argv, int code)
{
	if (argv[1] != NULL)
	{
		if (isNumber(argv[1]))
			code = _atoi(argv[1]);
		else
		{
			write(STDERR_FILENO, argv[0], _strLen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, argv[1], _strLen(argv[1]));
			write(STDERR_FILENO, ": Illegal number: ", 18);
			write(STDERR_FILENO, argv[1], _strLen(argv[1]));
			write(STDERR_FILENO, "\n", 1);
			code = 2;
		}
	}
	freeEnv();
	exit(code % 256);
}

/**
 * checkBuilt - checks for built in commands
 * @argv: argument vector
 * @source: source file name
 * @code: exit code
 * @ac: ...
 *
 * Return: 1 if built-in command found, 0 if not found
 */
int checkBuilt(int ac, char **argv, char *source, int code)
{
	int i = 0;
	if(isNumber(argv[1]) && ac > 2)
		{
			return (checkError(source,argv,6));
		}
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit_shell(argv, code);
		return (1);
	}

	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (argv[1] == NULL || argv[2] == NULL || argv[3] != NULL)
			return (checkError(source, argv, 8));
		if (_setenv(argv[1], argv[2], _atoi(argv[3])) == -1)
			return (checkError(source, argv, 8));
		return (1);
	}

	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (argv[1] == NULL || argv[2] != NULL)
			return (checkError(source, argv, 8));
		if (_unsetenv(argv[1]) == -1)
			return (checkError(source, argv, 8));
		return (1);
	}

	if (_strcmp(argv[0], "printenv") == 0)
	{
		while (environ[i])
		{
			write(STDIN_FILENO, environ[i], _strLen(environ[i]));
			write(STDIN_FILENO, "\n", 1);
			i++;
		}
		return (1);
	}

	if (_strcmp(argv[0], "history") == 0)
		return (0);

	return (0);
}

