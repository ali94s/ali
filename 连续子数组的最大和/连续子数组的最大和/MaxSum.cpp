#include<iostream>
using namespace std;
#include<assert.h>
//传引用来返回需要这个子串的起始位置
//这样设计的好处是既返回了最大和又能返回这个子串
int MaxSum(int *a, int len,int &start,int &end)
{
	assert(a != NULL || len <= 0);
	int MaxSum = 0;
	int CurSum = 0;
	for (int i = 0; i < len; i++)
	{
		//start = 0;
		CurSum += a[i];
		if (CurSum>MaxSum)
		{
			MaxSum = CurSum;
			end = i;
		}
		//当此时的sum的值是小于零的说明从这个数往后的子串的和一定比加上之前的数的和大
		if (CurSum < 0)
		{
			start = i + 1;
			CurSum = 0;
		}
	}
	return MaxSum;
}

int main()
{
	int a[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(a) / sizeof(a[0]);

	//返回子串的下标
	int start = 0;
	int end = 0;


	cout << MaxSum(a, len,start,end) << endl;

	for (int i = start; i <= end; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}