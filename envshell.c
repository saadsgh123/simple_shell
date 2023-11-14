#include "shell.h"
#include <string.h>

void envshell(char **env, int *status)
{
    if (env == NULL) {
        fprintf(stderr, "Error: Environment variables are NULL.\n");
        *status = 1;
        return;
    }

    int envCount = 0;

    while (env[envCount])
    {
        envCount++;
    }

    qsort(env, envCount, sizeof(char *), compare_env);
:w
    for (int index = envCount - 1; index >= 0; index--)
    {
        write(STDOUT_FILENO, env[index], strlen(env[index]));
        write(STDOUT_FILENO, "\n", 1);
    }

    *status = 0;
}

int compare_env(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}
