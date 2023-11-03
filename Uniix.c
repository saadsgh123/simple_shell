#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>  // Include for terminal input handling

void processInput(const char *input);
char *readLine(void);

int main(int ac, char **argv) {
    char *line = NULL;

    while (1) {
        line = readLine();

        if (line == NULL) {
            // Ctrl+D was pressed, add a newline and break
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Display the user's input in the prompt
        printf("(Eshell) $ %s\n", line);

        processInput(line);

        free(line);
    }

    return 0;
}

void processInput(const char *input) {

    if (strcmp(input, "ls") == 0) {
        printf("ls\n");
    } else if (strcmp(input, "cd") == 0) {
        printf("cd\n");
    } else {
        printf("Unknown command: %s\n", input);
    }
}

char *readLine(void) {
    char *lineptr;
    size_t n = 0;
    ssize_t read;
    printf("(Eshell) $");

    read = getline(&lineptr, &n, stdin);

    if (read == -1) {
        free(lineptr);
        return NULL;
    }

    if (read > 0 && lineptr[read - 1] == '\n') {
        lineptr[read - 1] = '\0';
    }

    return lineptr;
}

