//#include<iostream>
//using namespace std;
#include<stdio.h>
//给定一个矩阵，从外到内依次打印矩阵的元素
void PrintMatrixOneCircle(int (*a)[4], int row, int col, int start);
void PrintMatrix(int (*a)[4], int row, int col)
{
	if (a == NULL || col <= 0 || row <= 0)
		return;
	int start = 0;
	while (row > start * 2 && col > start * 2)
	{
		PrintMatrixOneCircle(a, row, col, start);
		start++;
	}
}

void PrintMatrixOneCircle(int (*a)[4],int row,int col,int start)
{
	int endrow = row - 1 - start;
	int endcol = col - 1 - start;
	for (int i = start; i <= endcol; i++)
	{
		printf("%d",a[start][i]);
		printf(" ");
	}
	if (start < endrow)
	{
		for (int i = start + 1; i <= endrow; i++)
		{
			printf("%d", a[i][endrow]);
			printf(" ");
		}
	}
	if (start < endcol&&start<endrow)
	{
		for (int i = endcol - 1; i >= start; i--)
		{
			printf("%d", a[endrow][i]);
			printf(" ");
		}
	}
	if (start < endcol&&start<endrow - 1)
	{
		for (int i = endrow - 1; i>=start; i--)
		{
			printf("%d", a[i][start]); 
			printf(" ");
		}
	}
}

int main()
{
	int a[4][4] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	PrintMatrix(a, 4, 4);
	getchar();
	return 0;
}