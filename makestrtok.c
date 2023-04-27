#include "shell.h"
char **makeStrtok(char *string)
{
	int i =0;
	size_t n = 1;
	char * token;
	char **argv;

	argv = malloc(sizeof(char *) * n);
	token = strtok(string," \n");
	while (token != NULL)
	{
		argv[i] = token;
		argv = _realloc(argv,++n * sizeof(char *));
		token = strtok(NULL," \n");
		i++;
	}

	argv[i] = NULL;
	return (argv);
}
