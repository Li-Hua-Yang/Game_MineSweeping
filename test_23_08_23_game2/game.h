#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 9	//棋盘行数
#define COL 9	//棋盘列数

#define ROWS ROW+2	//棋盘增大一圈，防止越界
#define COLS COL+2	//棋盘增大一圈，防止越界

#define Easy 10		//雷的个数

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);	//初始化函数
void DisPlay(char board[ROWS][COLS],int row, int col);	//棋盘显示函数
void SetMine(char board[ROWS][COLS], int row, int col);	//布置雷函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);	//扫雷函数
int GetMineCount(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y);	//计数函数

#endif // !__GAME_H__

