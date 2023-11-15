#include "shell.h"

void bultin(char **command, char **argv ,char **env , int *status, int idx)
{
    (void)argv;
    (void)idx;
    if(strcmp(command[0], "exit") == 0)
    {
        exitshell(command, status);
    }
    else if (strcmp(command[0], "env" ) == 0)
    {
        envshell(command,env, status);
    }
}