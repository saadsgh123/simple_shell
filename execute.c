
#include "shell.h"
#include <stdlib.h>
#include <stddef.h>



int _execute(char **cmd, char **env, char **argv, int idx) {
    char *fullcmd = NULL;
    pid_t child;
    
    fullcmd = Hnadlepath(cmd[0], env);
    if (fullcmd == NULL) {
        printerror(argv[0], cmd[0], idx);
        return 127;
    }

    child = fork();
    if (child == 0) {
        if (execve(fullcmd, cmd, env) == -1) {
            printerror(argv[0], cmd[0], idx); // Print an error message
            exit(127);
        }
    } else {
        free(fullcmd);
        int status;
        wait(&status);
        return status;
    }
}