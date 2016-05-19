#include<iostream>
using namespace std;
void MyQuickSort(int *a, int first, int last);
int FindNumber(int *a,int len)
{
	MyQuickSort(a, 0, len);

	return a[len/2];
}



//���ÿ�������  �ҵ��м���Ǹ���

//��Ϊ��һ�������г����˳���һ����������ֿ϶�λ���м����׿�����������ص�
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
	//����һ�������  ����м�����ǰ�����ֻ���ǰ��ν���һ�ο���
	if (end>(last / 2))
		MyQuickSort(a, first, end);
	//�Ժ��ν���һ�ο���
	if (end < (last / 2))
		MyQuickSort(a, end + 1, last);
	//�պ����м�ֱ�ӷ���
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