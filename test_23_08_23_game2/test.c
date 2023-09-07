#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"


void menu()
{
	printf("**********************************\n");
	printf("*********   1.PLAY     ***********\n");
	printf("*********   0.EXIT     ***********\n");
	printf("**********************************\n");
}

void game()
{
	//存储雷的信息
	char mine[ROWS][COLS] = { 0 };	//存放布置好的雷
	char show[ROWS][COLS] = { 0 };	//存放排查出的雷
	//初始化数组
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	SetMine(mine,ROW,COL);			//布置雷
	FindMine(mine,show,ROW,COL);	//扫雷
}	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}