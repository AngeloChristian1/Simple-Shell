#include "shell.h"

/**
 * _strtok - Tokenizes input command
 * @string: String to be tokenized
 *
 * Return: An array of strings
 */
char **_strtok(char *string)
{
	int i = 0;
	size_t n = 1;
	char *token;
	char **argv;

	argv = malloc(sizeof(char *) * n);
	token = strtok(string, " \n");
	while (token != NULL)
	{
		argv[i] = token;
		argv = _realloc(argv, ++n * sizeof(char *));
		token = strtok(NULL, " \n");
		i++;
	}
	argv[i] = NULL;
	return (argv);
}

