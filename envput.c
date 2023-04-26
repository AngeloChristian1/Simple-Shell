/**
 * navPath - tokenizes input command
 * @string: string got
 * @freeflag: free space
 *
 * Return: 1 on success
 */
int navPath(char **string, int *freeflag)
{
	char *path, *fileP, *full, *token;
	struct stat st;

	if (*string == NULL)
		return (-1);

	if (stat(*string, &st) == 0 && _strfind(*string, '/'))
		return (0);

	path = _getenv("PATH");
	if (!path)
		return (1);

	token = strtok(path, ":");
	while (token != NULL)
	{
		fileP = str_concat("/", *string);
		full = str_concat(token, fileP);
		free(fileP);
		if (stat(full, &st) == 0)
		{
			*freeflag = 1;
			free(*string);
			*string = full;
			free(path);
			return (0);
		}
		token = strtok(NULL, ":");
		free(full);
	}
	free(path);

	if (_strfind(*string, '/') == 0)
		return (3);

	return (1);
}

