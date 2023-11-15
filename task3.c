#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/wait.h>
#include <sys/stat.h>
int _execute(char **cmd, char **env, char**argv, int idx);
void bultin(char **command, char **argv ,char **env , int *status, int idx);
void exitshell(char **command , int *status);
int isbuiltin(char *command);
// Function declarations
char *intToA(int num);
void envshell (char **command , char **env , int *status);

char *readLine(int isInteractive);
char **tokenizeInput(char *line);
int compare_env(const void *a, const void *b) ;
char *Hnadlepath(char *cmd, char **env);
void printerror(char *name_shell, char *cmd, int numbre);

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


char *readLine(int isInteractive) {
    char *lineptr  = NULL;
    size_t n = 0;
    ssize_t read;

    if (isInteractive) {
        printf("$");
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

int _execute(char **cmd, char **env, char **argv, int idx) {
    char *fullcmd = NULL;
    pid_t child;
    
    fullcmd = Hnadlepath(cmd[0], env);
    if (fullcmd == NULL) {
        printerror(argv[0], cmd[0], idx);
        return 127;
    }

    child = fork();
    if (child == 0) {
        if (execve(fullcmd, cmd, env) == -1) {
            printerror(argv[0], cmd[0], idx); // Print an error message
            exit(127);
        }
    } else {
        free(fullcmd);
        int status;
        wait(&status);
        return status;
    }
}

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




char *Hnadlepath(char *cmd, char **env) {
    char *fullcmd = NULL, *directory = NULL;
    int modifiedSize = 0;
    struct stat st;
    int i = 0;
    while (cmd[i]) {
        if (cmd[i] == '/') {
            if (stat(cmd, &st) == 0) {
                return strdup(cmd);
            return (NULL);
            }
        }
        i++;
    }

    char *path = _getenvrament("PATH", env);

    if (path == NULL || *path == '\0') {
        free(path);
    
        return NULL;
    }

    directory = strtok(path, ":");

    while (directory) {
        modifiedSize = strlen(directory) + 2;
        fullcmd = (char *)malloc(modifiedSize);
        if (fullcmd) {
            strcpy(fullcmd, directory);
            strcat(fullcmd, "/");
            strcat(fullcmd, cmd);
            if (stat(fullcmd, &st) == 0) {
                free(path);
                return fullcmd;
            }
        }

        free(fullcmd);
        directory = strtok(NULL, ":");
    }

    free(path);

    return NULL;
}

void printerror(char *name_shell, char *cmd, int numbre) {
    char *index = NULL;
    char messag[] = ": not found\n";
    index = intToA(numbre);
    write(STDERR_FILENO, name_shell, strlen(name_shell));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, index, strlen(index));
    write(STDERR_FILENO, ": ", 2);

    write(STDERR_FILENO, cmd, strlen(cmd));
    write(STDERR_FILENO, messag, strlen(messag));
   free(index),index = NULL;
}
char *intToA(int num) {
    int temp = num;
    int numDigits = 1;
    while (temp >= 10) {
        temp /= 10;
        numDigits++;
    }

    char *str = (char *)malloc(numDigits + 1);
    if (str == NULL) {
        return NULL;
    }
    str[numDigits] = '\0'; 
    for (int i = numDigits - 1; i >= 0; i--) {
        str[i] = '0' + (num % 10);
        num /= 10;
    }

    int start = 0;
    int end = numDigits - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
return str;
}
int isbuiltin(char *command) {
    char *builtinCommands[] = {
        "cd", "pwd", "echo", "exit", "alias", "history", "export",
        "unset", "env", NULL
    };


    for (int i = 0; builtinCommands[i] != NULL; i++) {
        if (strcmp(builtinCommands[i], command) == 0) {
            return 1;
        }
    }

    return 0;
}





void bultin(char **command, char **argv ,char **env , int *status, int idx)
{
    (void)argv;
    (void)idx;
    if(strcmp(command[0], "exit") == 0)
    {
        exitshell(command, status);
    }
    else if (strcmp(command[0], "env" ) == 0)
    {
        envshell(command,env, status);
    }
}
void exitshell(char **command , int *status)
{
    if (*status == 0) {
        *status = 0;  // If status is 0 (no errors), set status to 2
    }
    else{
        *status = 2 ;
    }
    
        
    int i = 0;
 for (i = 0; command[i] != NULL; i++)
{
    free(command[i]);
    
}
exit(*status);
}

int compare_env(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}


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
