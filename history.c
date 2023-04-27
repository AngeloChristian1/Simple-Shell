#include "shell.h"
void histCall(char **string)
{
	int i = 0;

	while(string[i] != NULL)
	{
		write(1,string[i],_strLen(string[i]));
		write(1,"\n",1);
		i++;
	}
}
