#include<iostream>
using namespace std;
void Print1ToMaxOfN(int n);
bool CreateNumber(char *number);
void Print(char *a);
//给定一个整数n输出1到最大的n位数之间的的所有数

//算法1  先找到这个最大数n位数  通过循环输出
//存在的问题：没有考虑边界问题  如果n很大整形范围不够的时候怎么办？
//void Print1ToMaxOfN(int n)
//{
//	int num = 1;
//	while (n)
//	{
//		num *= 10;
//		n--;
//	}
//	for (int i = 0; i < num; i++)
//	{
//		cout << i << "";
//	}
//	cout << endl;
//}

//改进的算法2
void Print1ToMaxOfN(int n)
{
	//char a[n + 1] = { '0' };  //注意不能用这种写法  数组开辟空间时必须用常量
	char *number = new char[n + 1];
	memset(number, '0', n);//将前n个元素设置为字符0
	number[n] = '\0';
	while (!CreateNumber(number))
	{
		//cout << number << " ";
		Print(number);
	}
}


//字符串模拟整数加法
//模拟每次累加1
bool CreateNumber(char *number)
{
	bool IsOverFlow = false;
	int NTakeOver = 0;  //进位位
	int len = strlen(number);
	for (int i = len - 1; i >= 0; i--)
	{
		int sum = number[i] - '0' + NTakeOver;  //有进位的时候循环进来将当前位加上进位
		if (i == len - 1)
		{
			++sum;
		}
		if (sum >= 10)
		{
			if (i == 0)
			{
				IsOverFlow = true;
				break;
			}
			else
			{
				sum -= 10;
				NTakeOver = 1;  //进位
				number[i] = '0' + sum;
			}
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}
	return IsOverFlow;
}


//打印
void Print(char *a)
{
	char *tmp = a;
	while (*tmp == 0)  //遇到第一个非零的字符的时候在进行输出
		tmp++;
	while (*tmp!='\0')
	{
		cout << *tmp;
		tmp++;
	}
	cout << " ";
}
int main()
{
	Print1ToMaxOfN(4);
	getchar();
	return 0;
}