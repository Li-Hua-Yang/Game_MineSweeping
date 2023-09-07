#ifndef __GAME_H__
#define __GAME_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define ROW 9	//��������
#define COL 9	//��������

#define ROWS ROW+2	//��������һȦ����ֹԽ��
#define COLS COL+2	//��������һȦ����ֹԽ��

#define Easy 10		//�׵ĸ���

void InitBoard(char board[ROWS][COLS], int rows, int cols,char set);	//��ʼ������
void DisPlay(char board[ROWS][COLS],int row, int col);	//������ʾ����
void SetMine(char board[ROWS][COLS], int row, int col);	//�����׺���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);	//ɨ�׺���
int GetMineCount(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y);	//��������

#endif // !__GAME_H__

