#include<iostream>
using namespace std;
#include<assert.h>
//��������������Ҫ����Ӵ�����ʼλ��
//������Ƶĺô��Ǽȷ������������ܷ�������Ӵ�
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
		//����ʱ��sum��ֵ��С�����˵���������������Ӵ��ĺ�һ���ȼ���֮ǰ�����ĺʹ�
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

	//�����Ӵ����±�
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