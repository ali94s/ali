#include<iostream>
using namespace std;
int BinarySearch(int a[],int len,int key)
{
	if (!a||len < 0)
		return -1;
	int start = 0;
	int end = len - 1;
	int mid = 0;
	while (start < end)
	{
		//每次取中间
		mid = (start + end) / 2;
		if (a[mid]>key)
		{
			end = mid-1;
		}
		if (a[mid] < key)
		{
			start = mid + 1;
		}
		if (a[mid] == key)
			return a[mid];
	}
	//跳出循环的时候间隔已经不可分  要么这个数就是要找的数  要么就没有这个数
	if (a[start] == key)
		return a[start];
	else
		return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 8, 9, 12, 34 ,44};
	int ret = BinarySearch(a, 11, 9);
	cout << ret << endl;
	system("pause");
	return 0;
}