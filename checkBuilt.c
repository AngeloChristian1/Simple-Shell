#include "shell.h"
int isNumber(char *string)
{
	int i = 0;
	while(string[i])
	{
		if(string [i] < '0' || string [i] > '9')
			return (0);
		i++;
	}
	return (1);
}
int _atoi(char *s)
{
	int i,np = 0,c,d = 1,num = 0;

	for (i = 0; i < _strLen(s); i++)
	{
		if (!(s[i] >= '0' && s[i] <= '9') && c > 0)
			break;
		if (s[i] == '-')
			np--;
		if (s[i] == '+')
			np++;
		if (s[i] >= '0' && s[i] <= '9')
		{
			c++;
		}
	}
	while (c > 0)
	{
		num += ((s[i - 1] - '0') * d);
		i--;
		c--;
		d *= 10;
	}
	if (np >= 0)
	{
		num *= 1;
	} else
	{
		num *= -1;
	}
	return (num);
}
int checkBuilt(int ac, char **argv, char *source,int code)
{
	int i = 0;

	if(_strcmp(argv[0],"exit"))
	{
		int number;
		if(ac == 1)
		{
			free(argv[0]);
			free(argv);
			freeEnv();
			exit(code);
		}
		if(isNumber(argv[1]) && ac > 2)
		{
			return (errors(source,argv,6));
		}
		if(isNumber(argv[1]) == 0)
			return (errors(source,argv,7));
		number = _atoi(argv[1]);
		freeEnv();
		exit(number % 256);
	}

	if(_strcmp(argv[0],"setenv"))
	{
		if(ac == 4)
		{
			int overwrite = _atoi(argv[3]);
			if(_setenv(argv[1],argv[2],overwrite) == -1)
				return(errors(source,argv,8));
			return (1);
		}
		else
			return(errors(source,argv,8));
	}
	if(_strcmp(argv[0],"unsetenv"))
	{
		if(_unsetenv(argv[1]) == -1)
			return(errors(source,argv,8));
		return(1);
	}
	if(_strcmp(argv[0],"printenv"))
	{
		while(environ[i])
		{
			write(STDIN_FILENO,environ[i],_strLen(environ[i]));
			write(STDIN_FILENO,"\n",1);
			i++;
		}
		return(1);
	}
	if(_strcmp(argv[0],"history"))
		return (0);

	return(0);
}
