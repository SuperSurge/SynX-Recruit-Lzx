#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int player, computer;
    int player_score = 0, computer_score = 0;
    char input[10];
    int cheat_mode = 0;
    srand(time(NULL));

    printf("=== 猜拳游戏 (三局两胜) ===\n");
    printf("0-石头, 1-剪刀, 2-布\n");
    printf("输入 zzz 进入作弊模式\n");

    while (player_score < 2 && computer_score < 2)
    {
        printf("\n当前比分: 玩家 %d - %d 电脑\n", player_score, computer_score);
        printf("请出拳: ");
        scanf("%s", input);

        // 检查是否进入作弊模式
        if (strcmp(input, "zzz") == 0)
        {
            cheat_mode = 1;
            printf("*** 作弊模式激活! ***\n");
            continue;
        }

        // 转换为数字
        player = atoi(input);

        if (cheat_mode)
        {
            // 作弊模式：电脑永远输
            computer = (player + 1) % 3;
        }
        else
        {
            computer = rand() % 3;
        }

        printf("电脑出: %d\n", computer);

        if (player == computer)
        {
            printf("平局!\n");
        }
        else if ((player == 0 && computer == 1) ||
                 (player == 1 && computer == 2) ||
                 (player == 2 && computer == 0))
        {
            printf("你赢了这一局!\n");
            player_score++;
        }
        else
        {
            printf("你输了这一局!\n");
            computer_score++;
        }
    }

    if (cheat_mode)
    {
        printf("\n*** 作弊模式获胜 ***\n");
    }

    printf("\n最终比分: 玩家 %d - %d 电脑\n", player_score, computer_score);
    if (player_score > computer_score)
    {
        printf("恭喜你获得最终胜利!\n");
    }
    else
    {
        printf("很遗憾，电脑获胜!\n");
    }

    return 0;
}