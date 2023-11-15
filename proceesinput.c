#include "shell.h"
void processInput(char *line, char **argv, char **env) {
    int status = 0, i, j;
    int idx = 0;
    char **command = NULL;

    for (i = 0; line[i] != '\0'; i++) {
        if (line[i] != ' ' && line[i] != '\t') {
            idx++;
            break;
        }
    }

    if (idx == 0) {
        return;
    }

    command = tokenizeInput(line);

    if (command != NULL) {
        if (isbuiltin(command[0])) {
            bultin(command, argv, env, &status, idx);
        } else {
            status = _execute(command, env, argv, idx);
        }

        for (j = 0; command[j] != NULL; j++) {
            free(command[j]);
        }
        free(command);
    }
}
