#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

/////*****  ��ʼ������  *****/////
//board--������
//rows--��ʼ������
//cols--��ʼ������
//set--��ʼ���ַ�
//��ʼ����Χ��СΪ rows �� cols
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

/////*****  ������ʾ���� *****/////
//board--������
//row--��������
//col--��������
//��ʾ��Χ�� board[1][1] Ϊ��Ԫ�أ���СΪ row �� col
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

/////*****  �����׺���  *****/////
//board--������
//row--��������
//col--��������
void SetMine(char board[ROWS][COLS], int row, int col)
{
	int count = Easy;	//�׵ĸ���
	while (count)
	{
		int i = rand() % row + 1;	//���λ�÷���
		int j = rand() % col + 1;
		if (board[i][j] == '0')
		{
			board[i][j] = '1';
			count--;
		}
	}
}

/////*****  ���׺���  *****/////
//mine--��Ų��úõ���
//show--����Ų������
//row--��������
//col--��������
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win_count = 0;	//ʤ������������������ = �����ܸ��� - �׵�����������Ϸʤ��
	while (win_count < (row * col - Easy))	//�з���λ��δ�ҳ�������ѭ��
	{
		DisPlay(show, row, col);
		printf("�������Ų��׵����꣺>");
		scanf("%d%d", &x, &y);
		system("cls");
		if (x>=1 && x<=row && y>=1 && y<=col && show[x][y]=='*')	//�����������ڣ���δ������������Ϸ�
		{
			if (mine[x][y] == '1')	//����
			{
				printf("����\n");
				DisPlay(mine, row, col);
				break;
			}
			else	//�����ף��Ҹ�λ��δ��ɨ����ͳ����Χ�׵ĸ���
			{
				win_count = win_count + GetMineCount(mine, show, x, y);
			}
		}
		//����Ƿ�
		else
		{
			printf("����Ƿ�\n");
		}
	}
	if (win_count == (row * col - Easy))	//�������� = �����ܸ��� - �׵�����������Ϸʤ��
	{
		printf("��ϲ�㣡�Ѿ��ҳ�ȫ���ף�\n");
		DisPlay(mine, row, col);
	}
}

/////*****  ����������ͳ����Χ8��λ���׵ĸ��������ڵ��λ����ʾ����  *****/////
//mine--��Ų��úõ���
//show--����Ų������
//x--��ѯλ�õ�������
//y--��ѯλ�õ�������
int GetMineCount(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int count = 0;		//�׵ĸ�����������ͳ�Ƹ���һȦ8��λ���׵ĸ���
	int win_count = 0;	//ʤ����������ͳ���Ѿ���ѯ��λ�ø���
	//���뺯��������������������������ִ��
	//1��ͳ��λ�ó����������ƣ�1 <= x <= ROW����1<= y <= COL��
	//2����λ���Ѿ���ͳ�ƹ���������Ĭ��ֵ'*'���ݹ������������
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL && show[x][y] == '*')
	{
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				count = count + (mine[i][j] - '0');		//�����������ַ�'1'���棬ASCII��ֵ��'0'�����Ϊ1������һȦ8��λ�ã�����׵ĸ���
			}
		}
		show[x][y] = count + '0';	//�����λ���޸�Ϊ�׵ĸ���
		win_count = 1;
		if (show[x][y] == '0')		//���һȦ�׸���Ϊ0�����һȦ8��λ�ý���ͳ�ƣ�ֱ�����̱߽����ͳ�����ֲ�Ϊ0���ݹ�ʵ��
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