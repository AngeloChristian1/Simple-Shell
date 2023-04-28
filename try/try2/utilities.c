#include "shell.h"

/**
* _findC - finds the first occurrence of a character in a string
*
* @s1: pointer to a string
* @s2: character to search for
*
* Return: 1 if the character is found, 0 otherwise
*/

int _findC(const char *s1, char s2)
{
int i = 0;

while (s1[i])
{
if (s1[i++] == s2)
return (1);
}
return (0);
}

/**
* _strcmp - compares two strings
*
* @s1: pointer to first string
* @s2: pointer to second string
*
* Return: 1 if the strings are equal, 0 otherwise
*/

int _strcmp(const char *s1, const char *s2)
{
int i = 0;
if (s1 == NULL)
return (0);
while (s2[i])
{
if (s1[i] != s2[i])
break;
i++;
}
if (s2[i] == '\0')
return (1);
return (0);
}

/**
* _strdup - duplicates a string
*
* @str: pointer to string to duplicate
*
* Return: pointer to newly allocated space containing the duplicate string
*/

char *_strdup(const char *str)
{
int i;
int c = 0;
char *t;

if (str == NULL)
return (NULL);

while (str[c] != '\0')
c++;

t = malloc(sizeof(char) * (c + 1));

if (t == NULL)
return (NULL);

for (i = 0; i < c; i++)
t[i] = str[i];

t[i] = '\0';

return (t);
}

/**
* str_concat - concatenates two strings
*
* @s1: pointer to first string
* @s2: pointer to second string
*
* Return: pointer to newly allocated space containing the concatenated string
*/

char *str_concat(const char *s1, const char *s2)
{
int i, len1, len2;
char *conc;

i = 0;
len1 = 0;
len2 = 0;
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";
while (s1[i] != '\0')
{
i++;
len1++;
}

i = 0;
while (s2[i] != '\0')
{
i++;
len2++;
}
conc = malloc(sizeof(char) * (len1 + len2 + 1));
if (conc == NULL)
return (NULL);

for (i = 0; i < len1; i++)
{
conc[i] = s1[i];
}

for (i = 0; i < len2; i++)
{
conc[i + len1] = s2[i];
}
conc[i + len1] = '\0';
return (conc);
}

/**
* _realloc - reallocates a block of memory to a new size
*
* @ptr: pointer to old block of memory
* @new_size: new size for memory block
*
* Return: pointer to newly allocated space containing the resized memory block
*/

void *_realloc(void *ptr, unsigned int new_size)
{
void *ret = NULL;
char *write, *read;

if (new_size > 0 || ptr == NULL)
{
ret = malloc(new_size);
if (ret == NULL)
return (NULL);
}

if (new_size > 0 && ptr != NULL)
{
write = ret;
read = ptr;
while (new_size--)
{
*write++ = *read++;
}
}
free(ptr);
return (ret);
}

