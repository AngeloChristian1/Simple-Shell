#include "shell.h"
int navPath(char **string, int *freeflag)
{
	char *copy,*path, *compare = "PATH", *fileP,*full, *token;
	int i = 0;
	struct stat st;
	if(*string == NULL)
		return (-1);
	if(stat(*string,&st) == 0 && _findC(*string,'/'))
	  return (0);
	while(environ[i])
	{
		if(_strcmp(environ[i],compare))
			break;
		i++;
	}
	copy = _strdup(environ[i]);
	path = strtok(copy, "=");
	path = strtok(NULL,"=");
	if(path[0] == ':')
	{
		full = str_concat("./",*string);
		if(stat(full,&st) == 0)
		{
			free(copy);
			*string = full;
			return(0);
		}
	}
	token = strtok(path,":");
	while(token != NULL)
	{
		fileP = str_concat("/",*string);
		full = str_concat(token,fileP);
		free(fileP);
		if(stat(full,&st) == 0)
		{
			*freeflag = 1;
			free(copy);
			*string = full;
			return(0);
		}
		token = strtok(NULL,":");
		free(full);
	}
	free(copy);
        if(_findC(*string,'/') == 0)
		return(3);
	return (1);
}
