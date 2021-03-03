#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("退出游戏\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("输入无效，重新输入\n");
			break;
		}
	} while (input);
	return 0;
}