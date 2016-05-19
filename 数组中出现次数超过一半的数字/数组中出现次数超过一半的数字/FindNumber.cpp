#include<iostream>
using namespace std;
void MyQuickSort(int *a, int first, int last);
int FindNumber(int *a,int len)
{
	MyQuickSort(a, 0, len);

	return a[len/2];
}



//利用快速排序  找到中间的那个数

//因为在一个数组中出现了超过一半次数的数字肯定位于中间搜易可以利用这个特点
void MyQuickSort(int *a, int first, int last)
{
	if (a == NULL || last <= 0)
		return;
	if (first >= last)
		return;
	int key = a[first];
	int start = first;
	int end = last - 1;
	while (start < end)
	{
		while (start < end&&a[end] >= key)
			end--;
		if (a[end] < key)
			swap(a[end], a[start]);
		while (start < end&&a[start] <= key)
			start++;
		if (a[start]>key)
			swap(a[start], a[end]);
	}
	//经过一次排序后  如果中间数在前半段在只需对前半段进行一次快排
	if (end>(last / 2))
		MyQuickSort(a, first, end);
	//对后半段进行一次快排
	if (end < (last / 2))
		MyQuickSort(a, end + 1, last);
	//刚好在中间直接返回
	else
		return;
}



int main()
{

	int a[] = { 12, 32, 32, 54, 32, 32, 33, 32, 32, 4,55,43,23,32,32,32 };
	//MyQuickSort(a, 0, 9);
	cout << FindNumber(a, sizeof(a)/sizeof(a[0])) << endl;
	system("pause");
	return 0;
}