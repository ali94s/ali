#include<iostream>
using namespace std;
//找到一个数组中最小的前k个数
//使用快速排序
void MySort(int *a, int first, int last, int k);
void FindKMin(int *a, int len,int k)
{
	if (a == NULL || len <= 0 || k > len)
		return;
	MySort(a, 0, len, k);
}
void MySort(int *a,int first,int last,int k)
{
	if (first >= last)
		return;
	int start = first; int end = last - 1;
	int key = a[first];
	while (start < end)
	{
		while (start < end&&a[end] >= key)
			end--;
		if (a[end] < key)
			swap(a[start], a[end]);
		while (start < end&&a[start] <= key)
			start++;
		if (a[start]>key)
			swap(a[end], a[start]);
	}
	MySort(a, first, start, k);
	MySort(a, start + 1, last, k);
}
int main()
{
	int a[] = { 24, 57, 59, 73, 28, 97, 44, 33, 22 };
	FindKMin(a, sizeof(a) / sizeof(a[0]), 5);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}