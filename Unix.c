#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
char *tokenizeInput(const char *input);
void processInput(const char *input);
char *readLine(int isInteractive);

int main(int ac, char **argv) {
    char *line = NULL;
    int isInteractive = isatty(STDIN_FILENO);

    while (1) {
        line = readLine(isInteractive);

        if (line == NULL) {
            // Ctrl+D was pressed, add a newline and break
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        processInput(line);

        // Check if it's an interactive terminal before displaying the input
        if (isInteractive && line[0] != '\0') {
            printf("%s\n", line);
        }

        free(line);
    }

    return 0;
}

void processInput(const char *input) {
    // Your existing command processing logic remains the same
    // ...

    // Replace these lines with your actual command processing logic
    if (strcmp(input, "ls") == 0) {
        printf("ls\n");
    } else if (strcmp(input, "cd") == 0) {
        printf("cd\n");
    } else {
        printf("Unknown command: %s\n", input);
    }
}

char *readLine(int isInteractive) {
    char *lineptr;
    size_t n = 0;
    ssize_t read;
    
    if (isInteractive) {
        printf("(Eshell) $");
    }

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
char  *tokenizeInput(const char *input)
{
int counter;
char *copystring = strdup(input);
char *token = strtok(copystring, "\t\n");
char *tokenlist = NULL;
while(token)
{	counter++;
	token = strtok(NULL, "\t\n");
}
free(copystring);
tokenlist = (char *)malloc(sizeof(char *) * (counter + 1 ));
if(tokenlist = NULL)
{
	return (NULL);
}
for (int i = 0; i < counter + 1; i++)
	{
        tokenlist[i] =  token[i];
    	}




}
