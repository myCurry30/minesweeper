#pragma once
#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define mine_counts 10
void menu(void);
void game(void);
void init_board(char board[ROWS][COLS], int row, int col, char set);
void display_board(char board[ROWS][COLS], int row, int col);
void set_mine(char board[ROWS][COLS], int row, int col);
void find_mine(char board_mine[ROWS][COLS], char board_show[ROWS][COLS], int row, int col);
int count_mine(char board_mine[ROWS][COLS], int x, int y);
#endif