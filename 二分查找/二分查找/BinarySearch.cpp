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
		//ÿ��ȡ�м�
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
	//����ѭ����ʱ�����Ѿ����ɷ�  Ҫô���������Ҫ�ҵ���  Ҫô��û�������
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