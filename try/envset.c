#include "shell.h"

/**
 * _strLen - calculates the length of a string
 * @string: string to find the length of
 *
 * Return: length of the string
 */
int _strLen(char *string)
{
	int len = 0;

	while (string[len])
		len++;

	return (len);
}

/**
 * _setenv - set an environment variable
 * @name: the name of the variable
 * @value: the value of the variable
 * @overwrite: whether to overwrite an existing variable with the same name
 *
 * Return: 0 on success, or -1 on failure
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *newEnv, *nameCopy, *valCopy, *newPath;
	int envLen = 0, same = -1;

	if (name == NULL || _strfind(name, '='))
		return (-1);

	valCopy = str_concat(NULL, value);
	nameCopy = str_concat(NULL, name);

	while (environ[envLen])
	{
		if (_strcmp(environ[envLen], nameCopy))
		{
			same = envLen;
			break;
		}
		envLen++;
	}

	if (overwrite || same == -1)
	{
		newEnv = str_concat(nameCopy, "=");
		newPath = str_concat(newEnv, valCopy);
		if (same == -1)
			environ = _realloc(environ, (envLen + 2) * sizeof(char *));
		else
			free(environ[same]);
		environ[same + 1] = NULL;
		environ[same] = newPath;
		free(newEnv);
		free(nameCopy);
		free(valCopy);
		return (0);
	}

	free(nameCopy);
	free(valCopy);
	return (0);
}


/**
 * _unsetenv - unsets an environment variable
 * @name: name of the environment variable to unset
 *
 * Return: 0 on success, or -1 on failure
 */
int _unsetenv(const char *name)
{
	int envLen = 0, same = -1;

	if (name == NULL || _strfind(name, '='))
		return (-1);

	while (environ[envLen])
	{
		if (_strcmp(environ[envLen], name))
			same = envLen;
		envLen++;
	}

	if (same == -1)
		return (0);

	while (environ[same])
	{
		free(environ[same]);
		environ[same] = environ[same + 1];
		same++;
	}

	return (0);
}

/**
 * freeEnv - frees the environment
 */
void freeEnv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		free(environ[i]);
		i++;
	}
	free(environ);
}

/**
 * environmentCopy - copies the environment
 */
void environmentCopy(void)
{
	char **environmentCopy, *envString;
	int i, len = 0;

	while (environ[len])
		len++;

	environmentCopy = malloc(sizeof(char *) * (len + 1));

	for (i = 0; i < len; i++)
	{
		envString = str_concat(NULL, environ[i]);
		environmentCopy[i] = envString;
	}

	environmentCopy[i] = NULL;
	environ = environmentCopy;
}
/**
 * _getenv - get the value of an environment variable
 * @name: the name of the environment variable to look up
 *
 * Return: a pointer to the value of the environment variable, or NULL if the
 *         variable is not found
 */
char *_getenv( char *name)
{
        extern char **environ;
        char *value = NULL;
        size_t len = _strLen(name);
        int i;

        for (i = 0; environ[i] != NULL; i++)
        {
                if (_strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
                {
                        value = environ[i] + len + 1;
                        break;
                }
        }

        return(value);
}

