#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **argv){
char *Unix = "(Eshell) $ ";
char *lineptr;
size_t n = 0;
while(1)
{
  printf("%s", Unix);

  getline(&lineptr, &n, stdin);
  if (fgets(lineptr, n, stdin) == NULL)
  {
            break;
}
  return (0);

}
}
