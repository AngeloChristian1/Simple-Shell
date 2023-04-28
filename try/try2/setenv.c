#include "shell.h"
int _strLen(char *string)
{
	int len = 0;
	while(string[len])
		len++;
	return len;
}
int _setenv(const char *name, const char *value, int overwrite)
{
	char *newEnv,*nameCopy,*valCopy,*newPath;
	int envLen = 0, same = 0;

	if (name == NULL || _findC(name,'='))
		return (-1);
	valCopy = str_concat(NULL, value);
	nameCopy = str_concat(NULL, name);
	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],nameCopy))
		{
			same = envLen;
		}
		envLen++;
	}

	if (same)
	{
		if(overwrite)
		{
			newEnv = str_concat(nameCopy,"=");
			newPath = str_concat(newEnv,valCopy);
			free(newEnv);
			environ[same] = newPath;
			free(nameCopy);
			free(valCopy);
			return(0);
		}
		else
		{
			free(nameCopy);
			free(valCopy);
			return(0);
		}

	}
	environ = _realloc(environ,(envLen + 2) * sizeof(char*));
	newEnv = str_concat(nameCopy,"=");
	newPath = str_concat(newEnv,valCopy);
	free(newEnv);
	environ[envLen] = newPath;
	environ[envLen + 1] = NULL;
	free(nameCopy);
	free(valCopy);
	return (0);

}
int _unsetenv(const char *name)
{
	int envLen = 0, same = -1;

	if (name == NULL || _findC(name,'='))
		return (-1);

	while(environ[envLen])
	{
		if (_strcmp(environ[envLen],name))
		{
			same = envLen;
		}
		envLen++;
	}
	if(same == -1)
		return (0);
	while(environ[same])
	{
		free(environ[same]);
		environ[same] = environ[same + 1];
		same++;
	}
	return(0);
}

void freeEnv(void)
{
	int i = 0;

	while(environ[i] != NULL)
	{
		free(environ[i]);
		i++;
	}
	free(environ);
}

void envCopy(void)
{
	char **envCopy, *envString;
	int i, len = 0;

	while(environ[len])
		len++;

	envCopy = malloc(sizeof(char *) * (len + 1));
	for(i = 0; i < len; i++)
	{
		envString = str_concat(NULL,environ[i]);
		envCopy[i] = envString;
	}
	envCopy[i] = NULL;
	environ = envCopy;
}
