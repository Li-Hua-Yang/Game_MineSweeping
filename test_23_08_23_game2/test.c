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
	//�洢�׵���Ϣ
	char mine[ROWS][COLS] = { 0 };	//��Ų��úõ���
	char show[ROWS][COLS] = { 0 };	//����Ų������
	//��ʼ������
	InitBoard(mine, ROWS, COLS,'0');
	InitBoard(show, ROWS, COLS,'*');
	SetMine(mine,ROW,COL);			//������
	FindMine(mine,show,ROW,COL);	//ɨ��
}	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}