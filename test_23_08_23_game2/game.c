#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/////*****  初始化函数  *****/////
//board--数组名
//rows--初始化行数
//cols--初始化列数
//set--初始化字符
//初始化范围大小为 rows × cols
void InitBoard(char board[ROWS][COLS], int rows, int cols,char set)
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

/////*****  棋盘显示函数 *****/////
//board--数组名
//row--棋盘行数
//col--棋盘列数
//显示范围以 board[1][1] 为首元素，大小为 row × col
void DisPlay(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

/////*****  布置雷函数  *****/////
//board--数组名
//row--棋盘行数
//col--棋盘列数
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy;	//雷的个数
	while (count)
	{
		int i = rand() % row + 1;	//随机位置放雷
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}

/////*****  排雷函数  *****/////
//mine--存放布置好的雷
//show--存放排查出的雷
//row--棋盘行数
//col--棋盘列数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win_count = 0;	//胜利计数器，当计数器 = 棋盘总格数 - 雷的数量，则游戏胜利
	while (win_count < (row * col - Easy))	//有非雷位置未找出，进入循环
	{
		DisPlay(show, row, col);
		printf("请输入排查雷的坐标：>");
		scanf("%d%d", &x, &y);
		system("cls");
		if (x>=1 && x<=row && y>=1 && y<=col && show[x][y]=='*')	//坐标在棋盘内，且未被翻开，坐标合法
		{
			if (mine[x][y] == '1')	//踩雷
			{
				printf("踩雷\n");
				DisPlay(mine, row, col);
				break;
			}
			else	//不是雷，且该位置未被扫过，统计周围雷的个数
			{
				win_count = win_count + GetMineCount(mine, show, x, y);
			}
		}
		//坐标非法
		else
		{
			printf("坐标非法\n");
		}
	}
	if (win_count == (row * col - Easy))	//当计数器 = 棋盘总格数 - 雷的数量，则游戏胜利
	{
		printf("恭喜你！已经找出全部雷！\n");
		DisPlay(mine, row, col);
	}
}

/////*****  计数函数，统计周围8个位置雷的个数，并在点击位置显示个数  *****/////
//mine--存放布置好的雷
//show--存放排查出的雷
//x--查询位置的行坐标
//y--查询位置的列坐标
int GetMineCount(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;		//雷的个数计数器，统计格子一圈8个位置雷的个数
	int win_count = 0;	//胜利计数器，统计已经查询的位置个数
	//进入函数的两个限制条件，不满足则不执行
	//1、统计位置超出棋盘限制（1 <= x <= ROW）（1<= y <= COL）
	//2、该位置已经被统计过，不等于默认值'*'（递归结束的条件）
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL && show[x][y] == '*')
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				count = count + (mine[i][j] - '0');		//计数，雷用字符'1'代替，ASCII码值与'0'相减则为1，遍历一圈8个位置，则得雷的个数
			}
		}
		show[x][y] = count + '0';	//将点击位置修改为雷的个数
		win_count = 1;
		if (show[x][y] == '0')		//如果一圈雷个数为0，则对一圈8个位置进行统计，直到棋盘边界或者统计数字不为0，递归实现
		{
			win_count = win_count + GetMineCount(mine, show, x - 1, y - 1)
			+ GetMineCount(mine, show, x - 1, y)
			+ GetMineCount(mine, show, x - 1, y + 1)
			+ GetMineCount(mine, show, x, y - 1)
			+ GetMineCount(mine, show, x, y + 1)
			+ GetMineCount(mine, show, x + 1, y - 1)
			+ GetMineCount(mine, show, x + 1, y)
			+ GetMineCount(mine, show, x + 1, y + 1);
		}
	}
	return  win_count;
}