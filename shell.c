#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **argv){
char *Unix = "(Eshell) $ ";
char *lineptr;
size_t n = 0;
  printf("%s", Unix);

  getline(&lineptr, &n, stdin);
  printf("%s\n", lineptr);
  free(lineptr);
  return (0);
 

}
