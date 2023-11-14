#include "shell.h"
void exitshell(char **command , int *status)
{
    if (*status == 0) {
        *status = 0;  // If status is 0 (no errors), set status to 2
    }
    else{
        *status = 2 ;
    }
    
        
    int i = 0;
 while (command[i] != NULL) {
        free(command[i]);
        i++;
    }
    free(command);
exit(*status);
}
