#include "shell.h"

/**
 * main - This is the entry point for the shell program
 * @ac: The number of arguments passed to the program
 * @argv: An array of strings containing the arguments passed to the program
 *
 * Return: Always returns 0
 */
int main(__attribute__((unused)) int ac, char *argv[])
{
    int status;
    pid_t child;

    signal(SIGINT, SIG_IGN);
    environmentCopy();

    while (1)
    {
        char *code = getLine(0);
        line++;

        char **argvs = _strtok(code);
        int n = 0;
        while (argvs[n])
            n++;

        int built = checkBuilt(n, argvs, argv[0], 0);
        int fpath = 0;
        int freeflag = 0;

        if (built == 0)
        {
            fpath = navPath(&argvs[0], &freeflag);
            int track = checkError(argv[0], argvs, fpath);
            if (track != 0)
            {
                free(argvs);
                free(code);
                continue;
            }
        }
        else if (built == NULL)
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
