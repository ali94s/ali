#include<iostream>
using namespace std;


//ͳ�ƴ�1��n������������1���ֵĴ���
//��ͳ�㷨    �õ�һ�����ͽ��ж�10ȡ����  �ڽ��г�10
int CountOne(int n)
{
	int count = 1;
	if (n <= 0)
		count = 0;
	if (n < 10)
		count = 1;
	else
	{
		for (int i = 10; i <= n; i++)
		{
			int j = i;
			while (j)
			{
				if (j % 10 == 1)
					count++;
				j /= 10;
			}
		}
	}
	return count;
}



5
int main()
{
	cout << CountOne(15) << endl;
	system("pause");
	return 0;
}