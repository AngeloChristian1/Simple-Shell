
#include "shell.h"
/**
 * _strfind - finds for a character in a string
 * @*p: a string to search from
 * @t: a character to search
 *
 * nurn: 1 if character is found and 0 if not found
 */
int _strfind((const char *p,char t)
{
	int i = 0;

	while(p[i])
	{
		if(p[i++] == t)
		{
			return(1);
		}
	}
	return(0);
}

/**
 * _strcmp - compares two strings
 * @*p: string 1
 * @*t: string 2
 *
 * Return: 1 on success and 0 otherwise
 */
int _strcmp(char *p, const char*t)
{
        int i = 0;
	if(p == NULL)
	{
		return (0);
	}
	if (t == NULL)
	{
		continue;
	}
       for (i = 0; t[i]; i++)
	    {
          if (p[i] != t[i]) 
		  {
        break;
    }
  }
        if (t[i] == '\0')
        {
	       return (1);
        }      
        return (0);
}

/**
 * _strdup - duplicates a string
 * @*str: string to duplicate
 *
 * Return: the string on sucess or NULL on fail
 */
char *_strdupr(char *str)
{
        int i;
        int c = 0;
        char *t;

	if (str == NULL)
	{
	   return (NULL);
	}
                

        while (str[c] != '\0')
                c++;

        t = malloc(sizeof(char) * c + 1);

        if (t == NULL)
        {
		   return (NULL);
		}
                

        for (i = 0; i < c; i++)
		t[i] = str[i];

        return (t);

}

/**
 * _strcmp - joins two strings
 * @*p: string 1
 * @*t: string 2
 *
 * Return: the string on sucess or NULL on fail
 */
char *str_concat(const char *p, const char *t)
{
	int i, len1, len2;
        char *conc;

	i = 0;
        len1 = 0;
	len2 = 0;
	if (p == NULL)
		p = "";
        if (t == NULL)
		t = "";
	while (p[i] != '\0')
        {
                i++;
                len1++;
        }

	i = 0;
        while (t[i] != '\0')
        {
                i++;
                len2++;
        }
	conc = malloc(sizeof(char) * (len1 + len2 + 1));
	
        if (conc == NULL)
        {
		   return (NULL);
		}
		

        for (i = 0; i < len1; i++)
        {
		   conc[i] = p[i];
        }

        for (i = 0; i < len2; i++)
	    {
                conc[i + len1] = t[i];
        }
	conc[i + len1] = '\0';
	return (conc);
}

/**
 * _strcmp -  reallocates memory pointed to by ptr with snew 
 * @*ptr:  points to the memory block to be reallocated
 * @*snew: specifies the new size of the memory block
 *
 * Return: the pointer on sucess or NULL on fail
 */
void *_realloc(void *ptr, unsigned int snew)
{
	
        char *newad, *oldad;
        void *ret = 0;
        
        if (snew > 0 && ptr != 0)
        {
                newad = ret;
                oldad = ptr;
                while (snew)
                {
                        snew--;
                        *newad++ = *oldad++;
                }
        }
        
        if (snew > 0 || ptr == 0)
        {
                ret = malloc(snew);
                if (ret == 0)
                {
				    return (0);
				}
                        
        }
        
        free(ptr);
        return (ret);
}
