#include "shell.h"

char **tokenizeInput(char *line) {
    int counter = 0;
    char *copystring = strdup(line);
    char *token = strtok(copystring, " \t\n");
    char **tokenList = NULL;

    while (token) {
        tokenList = realloc(tokenList, (counter + 1) * sizeof(char *));
        tokenList[counter++] = strdup(token);
        token = strtok(NULL, " \t\n");
    }

    tokenList = realloc(tokenList, (counter + 1) * sizeof(char *));
    tokenList[counter] = NULL;

    free(copystring);

    return tokenList;
}
