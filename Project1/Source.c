#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void find(char maze[][11], int start[]) //��_�I(�@�ߦb�k��)��Jstart[2]={X,Y} 
{
	for (int i = 0; i < 11; i++)
	{
		if (maze[i][0] == '.')
		{
			start[0] = 0;
			start[1] = i;
			break;
		}
	}
}
int findend(char maze[][11], int start[], int x, int y, int dir) //�����Ireturn 1 �Ϥ���0
{
	maze[y][x] = 'X';
	if (maze[y][10] == 'X' && x == 10) //���I�@�ߦb��(��������)
		return 1;

	int checkrighty[4] = { 1,0,-1,0 };
	int checkrightx[4] = { 0,-1,0,1 };
	int checktowardy[4] = { 0,1,0,-1 };
	int checktowardx[4] = { 1,0,-1,0 };
	int move = 0;

	if (maze[y + checkrighty[dir]][x + checkrightx[dir]] != '#')
	{
		move = 1;
		y += checkrighty[dir];
		x += checkrightx[dir];
		dir = (dir + 1) % 4;
	}
	else
	{
		if (maze[y + checktowardy[dir]][x + checktowardx[dir]] == '#')
			dir = dir - 1 < 0 ? 3 : dir - 1;
		dir = dir - 1 < 0 ? 3 : dir - 1;
	}
	if (move == 1 && x == 0)//¶�^���I�N��S�����I
		return 0;
	findend(maze, start, x, y, dir);
}

void print(char maze[][11])
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	FILE* Input;
	if ((Input = fopen("input.txt", "r")) == NULL)
	{
		printf("error");
		return 0;
	}
	char maze[11][11];
	for (int i = 0; i < 11; i++) //input
	{
		for (int j = 0; j < 11; j++)
		{
			maze[i][j] = fgetc(Input);//Ū�C��r
		}
		fgetc(Input);//Ū����'\n'
	}

	int start[2] = { -1,-1 };
	find(maze[0], start);
	if (findend(maze, start, start[0], start[1], 0))
		printf("Have a solution\n");
	else
		printf("No solution\n");
	print(maze);

}