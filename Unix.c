#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void processInput(const char *input);
char *readLine(void);
int main(int ac, char **argv)
{
char *line;

    while (1) {

        line = NULL;
	line = readLine();
        processInput(line);
	printf("%s\n", line);
	/*
        if (strcmp(line, "exit") == 0) {
            break;
        }
	if (strcmp(line, "NULL") == 0) {
            break;
        }
	*/
	write(STDOUT_FILENO, line, strlen(line));
   	 write(STDOUT_FILENO, "\n", 1);


    }	


    free(line);
    return 0;
}
void processInput(const char *input) {
    if (strcmp(input, "ls") == 0) {
        printf("ls");
    } else if (strcmp(input, "cd") == 0) {
         printf("ls");
    } else if (strcmp(input, "mkdir") == 0) {
         printf("ls");
    } else if (strcmp(input, "rm") == 0) {
         printf("ls");
    } else if (strcmp(input, "cp") == 0) {
         printf("ls");
    } else if (strcmp(input, "mv") == 0) {
         printf("ls");
    } else if (strcmp(input, "cat") == 0) {
         printf("ls");
    } else if (strcmp(input, "echo") == 0) {
         printf("ls");
    } else if (strcmp(input, "pwd") == 0) {
         printf("ls");
    } else if (strcmp(input, "clear") == 0) {
         printf("ls");
    } else if (strcmp(input, "date") == 0) {
      	 printf("ls");;
    } else if (strcmp(input, "who") == 0) {
         printf("ls");
    } else if (strcmp(input, "cal") == 0) {
         printf("ls");
    } else {
        printf("Unknown command: %s\n", input);
    }
}
char *readLine(void)
{
char *lineptr;
size_t n = 0;
ssize_t read;
printf("(Eshell) $");
read = getline(&lineptr, &n, stdin);
if(read == -1)
{
      	free(lineptr);
	return (NULL);
}	

return (lineptr);


}
