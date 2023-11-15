#include "shell.h"
void processInput(char *line, char **argv, char **env) {
    int status = 0;
    int idx = 0;
    char **command = NULL;

    for (int i = 0; line[i] != '\0'; i++) {
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

        for (int i = 0; command[i] != NULL; i++) {
            free(command[i]);
        }
        free(command);
    }
}