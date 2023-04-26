#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
extern char **environ;
extern int line;
int _strfind(const char *s1, char s2);
char *getLine(int code);
char **_strtok(char *string);
char *getPath(char *string);
int _strcmp(char *p, const char *t);
char *_strdupr(char *str);
char *str_concat(const char *s1, const char *s2);
int navPath(char **string, int *free);
void *_realloc(void *ptr, unsigned int new_size);
int checkBuilt(char **argv, char *source, int code);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
int _strLen(char *string);
void histCall(char **string);
int checkError(int ac, char *source, char **command, int code);
char *int_string(int digits);
void environmentCopy(void);
void exit_shell(char **argv, int code);
void freeEnv(void);
#endif

