#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("**************ɨ��*************\n");
	printf("******[1]play     [0]exit******\n");
	printf("*******************************\n");
}

void game(void)
{
	//��������
	char mine[ROWS][COLS] = { 0 };//�����洢�׵���Ϣ
	char show[ROWS][COLS] = { 0 };//�����������ʾ
	//��ʼ�����̣�
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//��ӡ����
	//display_board(mine, ROW, COL);
	display_board(show, ROW, COL);
	//����
	set_mine(mine, ROW, COL);
	//display_board(mine, ROW, COL);
	//ɨ��
	find_mine(mine,show,ROW, COL);
}


void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void display_board(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}


void set_mine(char board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = mine_counts;
	while (count)
	{
		x = rand() % row + 1;//1-9
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}


void find_mine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	//�ܹ�9*9-10=71���ط�û���ף�ÿ����һ������count_end��1��count_end==0��ʾɨ�׳ɹ�
	int count_end = ROW * COL - mine_counts;
	while (count_end)
	{
		printf("��������>:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if(board_mine[x][y] != '1')
			{
				count = count_mine(board_mine, x, y);
				board_show[x][y] = count + '0';
				display_board(board_show, row, col);
				count_end--;
			}
			else
			{
				printf("ɨ��ʧ��\n");
				display_board(board_mine, row, col);
				break;
			}
		}
		else
		{
			printf("����Ƿ�,����������\n");
		}
	}
	if (count_end == 0)
	{
		printf("��ϲ��ɨ�׳ɹ���\n");
		display_board(board_mine, row, col);
	}
}

//'1' - '0' = 1
//'0' - '0' = 0
//'3' - '1' = 2

int count_mine(char board_mine[ROWS][COLS], int x, int y)
{
	return board_mine[x - 1][y] +
		board_mine[x - 1][y + 1] +
		board_mine[x][y + 1] +
		board_mine[x + 1][y + 1] +
		board_mine[x + 1][y] +
		board_mine[x + 1][y - 1] +
		board_mine[x][y - 1] +
		board_mine[x - 1][y - 1] - 8 * '0';
}