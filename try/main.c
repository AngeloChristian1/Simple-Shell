#include "shell.h"

/**
 * main - Entry point for the shell program
 * @ac: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: Always returns 0
 */

int main(__attribute__((unused)) int ac, char *argv[])
{
    int i = 0;
    int freeflag = 0;
    int n = 0;
    int status;
    int built = 0;
    int track = 0;
    int fpath = 0;
    char **argvs;
    char *code;
    pid_t child;

    signal(SIGINT, SIG_IGN);
    environmentCopy();

    while (i == 0)
    {
        code = getLine(track);
        line++;
        argvs = _strtok(code);

        while (argvs[n])
            n++;

        built = checkBuilt(n, argvs, argv[0], track);
        n = 0;

        if (built == 0)
        {
            fpath = navPath(&argvs[0], &freeflag);
            track = checkError(argv[0], argvs, fpath);
        }
        track = built;

        if (built == -1)
        {
            continue;
        }

        if (argvs[0] == NULL || built != 0 || fpath != 0)
        {
            free(argvs);
            free(code);
            continue;
        }

        child = fork();

        if (child == 0)
        {
            if (execve(argvs[0], argvs, environ) == -1)
            {
                checkError(argv[0], argvs, 4);
            }
        }
        else
        {
            wait(&status);
        }
        free(argvs);
        free(code);
    }

    return (0);
}

