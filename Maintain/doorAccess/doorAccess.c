#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>



int main (int argc, char * argv[])
{

  char ID[100] = {0};
  char delID[100] = {0};
  char ch[100] = {0};
  char pass [100][9] = {"ABCDEFFF", "DEADDEAD", "87654321"};
  int idx = 3;


  SYS_LOOP:
  while (1)
  {
    printf("Please input a Card Number:");
    scanf("%s", ID);

    if (strcmp("7FEEDCAD", ID) == 0)
    {
      SUPER_USER:
                printf("SUPER USER Mode\n");
                printf("Add new pass(A) , delete pass(D) or exit SUPER USER Mode(E)?\n");
                scanf("%c", ch);
                switch (ch[0])
                {
                case 'A':
                  printf("Add new pass:\n");
                  scanf("%s", pass[idx++]);
                  printf("Add successful!\n");
                  goto SUPER_USER;
                
                case 'D':
                  printf("Delete pass:\n");
                  scanf("%s", delID);
                  for (int i = 0; i < idx; i++)
                  {
                    if (strcmp(pass[i], delID) == 0)
                    {
                      memset(pass[i], '\0', strlen(pass[i] + 1));
                      printf("Delete successful");
                      goto SUPER_USER;
                    }
                    
                  }
                  printf("Invalid card number\n");
                  goto SUPER_USER;
                case 'E':
                  goto SYS_LOOP;
                default:
                  goto SUPER_USER;
                  
                }
    }
    

    for (int i = 0; i < sizeof(pass); i++)
    {
      if (strcmp(pass[i], ID) == 0)
      {
        printf("Correct card number\n");
        goto SYS_LOOP;
      }       
           
    }
      printf("Invalid card number\n");
  }
  


  

  
  
  


  return 0;
}