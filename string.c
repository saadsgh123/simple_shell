#include "shell.h"
#include <stdlib.h>

char *_strcpy(char *dest, const char *src) {
    char *originalDest = dest; // Keep track of the original destination

    // Copy characters from source to destination
    while ((*dest++ = *src++) != '\0') {
        // continue copying until null terminator is encountered
    }

    return originalDest; // Return the original destination
}
#include <stddef.h>

char *_strcat(char *dest, const char *src) {
    size_t dest_len = _strlen(dest);
    size_t i;

    for (i = 0; src[i] != '\0'; ++i) {
        dest[dest_len + i] = src[i];
    }

    dest[dest_len + i] = '\0';

    return dest;
}

char *_strtok(char *str, const char *delim) {
    static char *lastToken = NULL; // Keep track of the last token

    if (str != NULL) {
        lastToken = str; // If a new string is provided, update the lastToken
    } else if (lastToken == NULL) {
        return NULL; // If no new string and no lastToken, return NULL
    }

    // Find the beginning of the token (skip leading delimiters)
    while (*lastToken != '\0' && strchr(delim, *lastToken) != NULL) {
        lastToken++;
    }

    // If no more tokens are found, return NULL
    if (*lastToken == '\0') {
        return NULL;
    }

    // Save the current position of lastToken
    char *tokenStart = lastToken;

    // Find the end of the token (skip non-delimiters)
    while (*lastToken != '\0' && strchr(delim, *lastToken) == NULL) {
        lastToken++;
    }

    // If a token is found, null-terminate it and update lastToken
    if (*lastToken != '\0') {
        *lastToken++ = '\0';
    }

    return tokenStart; // Return the start of the current token
}
char *_strdup(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    size_t len = strlen(str) + 1; // Include space for the null terminator
    char *copy = (char *)malloc(len);

    if (copy != NULL) {
        strcpy(copy, str);
    }

    return copy;
}
int _strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }

    if (*str1 == *str2) {
        return 0; // Strings are equal
    } else if (*str1 < *str2) {
        return -1; // str1 is less than str2
    } else {
        return 1; // str1 is greater than str2
    }
}

size_t _strlen(const char *str) {
   size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}