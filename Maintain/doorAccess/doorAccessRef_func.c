#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addPass(char **_pass, int *_idx)
{
    printf("新增卡號: ");
    scanf("%s", _pass[(*_idx)++]);
    printf("新增成功\n");
}

void delPass(char **_pass, int _idx)
{
    char delID[100] = {0};
    printf("刪除卡號: ");
    scanf("%s", delID);
    for (int i = 0; i < _idx; i++)
        if (strcmp(_pass[i], delID) == 0)
        {
            memset(_pass[i], '\0', strlen(_pass[i]) + 1);
            printf("刪除成功\n");
            return;
        }
    printf("查無此卡號\n");
}

void accessDoor(char *_ID, char **_pass, int _idx)
{
    for (int i = 0; i < _idx; i++)
        if (strcmp(_pass[i], _ID) == 0)
        {
            printf("允許進入\n");
            return;
        }
    printf("無效卡號\n");
}

int main(int argc, char *argv[])
{
    char ID[100] = {0};
    char **pass = (char **)calloc(sizeof(char *), 100);
    for (int i = 0; i < 100; i++)
        pass[i] = (char *)calloc(sizeof(char), 9);
    // char pass1[100][9] = {"ABCDEFFF", "DEADDEAD", "87654321"};
    strcpy(pass[0], "ABCDEFFF");
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

    return 0;
}
