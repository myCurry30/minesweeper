#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			printf("�˳���Ϸ\n");
			break;
		case 1:
			game();
			break;
		default:
			printf("������Ч����������\n");
			break;
		}
	} while (input);
	return 0;
}