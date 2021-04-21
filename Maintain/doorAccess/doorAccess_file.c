#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define N 100
#define M 100

int main (int argc, char * argv[])
{
  char temp[N][M];
  int n = 0;
  FILE * FD;
  FD = fopen("cardNumbers.txt", "r");
  
  if (FD == NULL)
  {
    printf("Fail to open file!\n");
    return EOF;
  }
  
  while (n < N && fgets(temp[n], sizeof(* temp), FD) != NULL)
  {
    puts(temp[n]);
    n++;
      
   
  }



      return 0;
}