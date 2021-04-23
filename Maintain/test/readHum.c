#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "readHum.h"

#define N 100
#define M 100

char readHum()
{
  char temp[N][M];
  int n = 0;
  FILE *FD;
  //remaber to change txt path
  FD = fopen("Humidity.txt", "r");

  if (FD == NULL)
  {
    printf("Fail to open file!\n");
    return EOF;
  }
  //change 2 to other val if you want read more values on yout txt file
  fread(temp, sizeof(char), 2, FD);
  

  fclose(FD);

  return printf("%s\n", temp);
};