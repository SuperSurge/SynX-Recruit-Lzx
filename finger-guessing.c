#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int player, device;
    srand(time(NULL));
    printf("猜拳游戏（0：石头、1：剪刀、2：布）\n");
    while (1)
    {
        printf("请出拳：\n");
        scanf("%d", &player);
        device = rand() % 3;
        if (player != 0 && player != 1 && player != 2)
        {
            printf("请正确出拳：0、1、2！\n");
            continue;
        }
        printf("玩家：%d vs 电脑：%d\n", player, device);
        if (player == device)
        {
            printf("平局\n");
        }
        else if ((player == 0 && device == 1) || (player == 1 && device == 2) || (player == 2 && device == 0))
        {
            printf("你赢了\n");
            break;
        }
        else
        {
            printf("你输了，请继续\n");
        }
    }

    return 0;
}