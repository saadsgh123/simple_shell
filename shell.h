#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <sys/wait.h>
#include <sys/stat.h>

char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
char *_strchr(const char *str, int c);
char *_strtok(char *str, const char *delim);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);
size_t _strlen(const char *str);
int _execute(char **cmd, char **env, char**argv, int idx);
void bultin(char **command, char **argv ,char **env , int *status, int idx);
void exitshell(char **command , int *status);
int isbuiltin(char *command);
char *checkInDirectory(char *cmd, char *directory);
char *intToA(int num);
void envshell(char **command, char **env, int *status);
char *_getenvrament(char *val, char **env);
char *readLine(int isInteractive);
char **tokenizeInput(char *line);
int compare_env(const void *a, const void *b) ;
char *Hnadlepath(char *cmd, char **env);
void printerror(char *name_shell, char *cmd, int numbre);
void processInput(int *status, char **argv, char **env);
void processInput2(char *line, char **argv, char **env);
void processCmd(char **command, char **argv, char **env, int *status, int idx);

#endif
