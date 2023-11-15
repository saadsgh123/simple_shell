
#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char *_getenvrament(char *val, char **env) {
    if (val == NULL || env == NULL) {
        return NULL;
    }

    int i = 0;
    while (env[i]) {
        char *copy = strdup(env[i]);
        char *copykey = strtok(copy, "=");

        if (copykey && strcmp(copykey, val) == 0) {
            char *value = strtok(NULL, "\n");
            if (value) {
                char *env2 = strdup(value);
                free(copy);
                return env2;
            }
        }

        free(copy);
        i++;
    }

    return NULL;
}
