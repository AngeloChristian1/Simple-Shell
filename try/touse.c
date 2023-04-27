#include "shell.h"

/**
 * _strfind - finds a character in a string
 * @p: a string to search from
 * @t: a character to search
 *
 * Return: 1 if character is found and 0 if not found
 */
int _strfind(const char *p, char t)
{
    int i = 0;

    while (p[i])
    {
        if (p[i++] == t)
        {
            return (1);
        }
    }
    return (0);
}

/**
 * _strcmp - compares two strings
 * @p: string 1
 * @t: string 2
 *
 * Return: 1 on success and 0 otherwise
 */
int _strcmp(char *p, const char *t)
{
    int i = 0;

    if (p == NULL)
    {
        return (0);
    }
    if (t == NULL)
    {
        return (0);
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
 * @str: string to duplicate
 *
 * Return: the string on success or NULL on fail
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
    {
        c++;
    }

    t = malloc(sizeof(char) * (c + 1));

    if (t == NULL)
    {
        return (NULL);
    }

    for (i = 0; i < c; i++)
    {
        t[i] = str[i];
    }

    return (t);
}

/**
 * str_concat - joins two strings
 * @p: string 1
 * @t: string 2
 *
 * Return: the string on success or NULL on fail
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
 * _realloc - reallocates memory pointed to by ptr with snew
 * @ptr: points to the memory block to be reallocated
 * @snew: specifies the new size of the memory block
 *
 * Return: the pointer on success or NULL on fail
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



/**
 * _strncmp - Compares two strings
 *
 * @s1: The first string to compare
 * @s2: The second string to compare
 * @n: The maximum number of characters to compare
 *
 * Return: 0 if the strings match, otherwise an integer less than zero if
 * s1 is less than s2, or greater than zero if s1 is greater than s2.
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
        size_t i = 0;

        while ((i < n) && (s1[i] != '\0') && (s2[i] != '\0'))
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }

        if (i == n)
                return (0);

        return (s1[i] - s2[i]);
}



/**
 * _getcwd - get current working directory
 *
 * Return: pointer to current working directory on success, NULL on failure
 */
char *_getcwd(void)
{
        char *buf = NULL;
        size_t size = 0;

        while (1)
        {
                buf = realloc(buf, size + BUFSIZ);
                if (!buf)
                        return (NULL);

                if (getcwd(buf, size + BUFSIZ) == buf)
                        return (buf);

                if (errno != ERANGE)
                        return (NULL);

                size += BUFSIZ;
		return(size);
        }
}
