#include "shell.h"

void processCommand(char **command, char **argv, char **env, int *status, int idx) {
    int i = 0;
    if (command != NULL) {
        for (i = 0; command[i] != NULL; i++)
        {
            if (strcmp(command[i], "") != 0)
            {
            }
        }

        if (isbuiltin(command[0])) {
            bultin(command, argv, env, status, idx);
        } else {
            *status = _execute(command, env, argv, idx);
        }

        for (i = 0; command[i] != NULL; i++)
        {
            free(command[i]);
        }
        free(command);
    }
}

void processInput(int *status, char **argv, char **env)
{
    int idx = 0, i, isEmpty = 1;
    char *line = NULL;
    char **command = NULL;
    int isInteractive = isatty(STDIN_FILENO);

    while (1)
    {
        line = readLine(isInteractive);

        if (line == NULL) {
            if (isInteractive) {
                write(STDOUT_FILENO, "\n", 1);
                break;
            }

            return;
        }

        for (i = 0; line[i] != '\0'; i++)
        {
            if (line[i] != ' ' && line[i] != '\t')
            {
                isEmpty = 0;
                break;
            }
        }

        if (isEmpty) {
            free(line);
            continue;
        }

        idx++;

        command = tokenizeInput(line);
        free(line);

        processCommand(command, argv, env, status, idx);
    }
}

int main(int argc, char **argv, char **env)
{
    int status = 0;
    (void)argc;

    processInput(&status, argv, env);

    return status;
}
