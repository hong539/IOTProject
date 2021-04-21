#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 100
#define M 100

int main (int argc, char * argv[])
{
  char temp[N][M];
  int n = 0;
  FILE * FD;
  FD = fopen("Humidity.txt", "r");
  
  if (FD == NULL)
  {
    printf("Fail to open file!\n");
    return EOF;
  }

  fread(temp, sizeof(char), 5, FD);
  printf("%s\n", temp);



  fclose(FD);

  return 0;
}