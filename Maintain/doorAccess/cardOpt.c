/* cardOpt.c */
 
#include <stdio.h>
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
