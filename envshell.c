#include "shell.h"
#include <string.h>

void envshell(char **command, char **env, int *status) {
    (void)command;
    (void)status;

    int i = 0;

    // Count the number of environment variables
    while (env[i]) {
        i++;
    }

    // Sort the environment variables
    qsort(env, i, sizeof(char *), compare_env);

    // Print the sorted environment variables
    for (int j = i - 1; j >= 0; j--) {
        write(STDOUT_FILENO, env[j], strlen(env[j]));
        write(STDOUT_FILENO, "\n", 1);
    }
  /* for (int j = 0; j < i; j++) {
        write(STDOUT_FILENO, env[j], strlen(env[j]));
        write(STDOUT_FILENO, "\n", 1);
    }
*/
    // Free the command array
    

    (*status) = 0;
}

int compare_env(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}
