#include "shell.h"


int main(int argc, char **argv, char **env) {
    int status = 0;
    int idx = 0; // Initialize idx
    char *line = NULL;
    int isInteractive = isatty(STDIN_FILENO);
    (void)argc;

    while (1) {
        line = readLine(isInteractive);

        if (line == NULL) {
            if (isInteractive) {
                write(STDOUT_FILENO, "\n", 1);
                break;
            }

            return (status);
        }

        int i;
        int isEmpty = 1;
        for (i = 0; line[i] != '\0'; i++) {
            if (line[i] != ' ' && line[i] != '\t') {
                isEmpty = 0;
                break;
            }
        }

        if (isEmpty) {
            free(line);
            continue;
        }


        idx++;

        char **command = tokenizeInput(line);

        if (command != NULL) {
            for (i = 0; command[i] != NULL; i++) {
                if (strcmp(command[i], "") != 0) {
                }
            }
            if(isbuiltin(command[0]))
            {
                bultin(command ,argv ,env,&status,idx);
            }
            else{

                    status = _execute(command, env, argv, idx);
            }

            

            for (i = 0; command[i] != NULL; i++) {
                free(command[i]);
            }
            free(command);
        }

        free(line);
    }

    return status; // Return the status code here
}

