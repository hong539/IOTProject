/* doorAccess.c */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include "cardOpt.h"
 
int main(int argc, char *argv[])
{
    char ID[100] = {0};
    char **pass = (char **) calloc(sizeof(char *), 100);
    for (int i = 0; i < 100; i++)
        pass[i] = (char *) calloc(sizeof(char), 9);
    strcpy(pass[0], "ABCDEFFF"); // pass[0] = "ABCDEFFF"
    strcpy(pass[1], "DEADDEAD");
    strcpy(pass[2], "87654321");
    int idx = 3;
 
SYS_LOOP:
    while (1)
    {
        printf("請輸入卡號: ");
 
        scanf("%s", ID);
 
        char ch[100];
        if (strcmp("7FEEDCAD", ID) == 0)
        {
        SUPER_USER:
            printf("超級使用者模式:\n");
            printf("請問要新增卡號(a) 移除卡號 (d) 還是 離開超級使用者系統 (e):");
            scanf("%s", ch);
            switch (ch[0])
            {
            case 'a': //新增卡號
                addPass(pass, &idx);
                goto SUPER_USER;
            case 'd': //移除卡號
                delPass(pass, idx);
                goto SUPER_USER;
            case 'e':
                goto SYS_LOOP;
            default:
                goto SUPER_USER;
            }
        }
 
        accessDoor(ID, pass, idx); //判斷卡號是否可以進入
    }
 
    for (int i = 0; i < 100; i++)
        free(pass[i]);
    free(pass);
 
    return 0;
}
