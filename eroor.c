#include "shell.h"

void printerror(char *name_shell, char *cmd, int numbre) {
    char *index = NULL;
    char messag[] = ": not found\n";
    index = intToA(numbre);
    write(STDERR_FILENO, name_shell, strlen(name_shell));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, strlen(index));
    write(STDERR_FILENO, ": ", 2);

    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, messag, strlen(messag));
   free(index),index = NULL;
}
