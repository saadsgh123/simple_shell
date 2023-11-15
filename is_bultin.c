#include "shell.h"

int isbuiltin(char *command) {
	int i;
    char *builtinCommands[] = {
        "cd", "pwd", "echo", "exit", "alias", "history", "export",
        "unset", "env", NULL
    };


    for (i = 0; builtinCommands[i] != NULL; i++) {
        if (strcmp(builtinCommands[i], command) == 0) {
            return 1;
        }
    }

    return 0;
}
