#include<iostream>
using namespace std;
void Print1ToMaxOfN(int n);
bool CreateNumber(char *number);
void Print(char *a);
//����һ������n���1������nλ��֮��ĵ�������

//�㷨1  ���ҵ���������nλ��  ͨ��ѭ�����
//���ڵ����⣺û�п��Ǳ߽�����  ���n�ܴ����η�Χ������ʱ����ô�죿
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

//�Ľ����㷨2
void Print1ToMaxOfN(int n)
{
	//char a[n + 1] = { '0' };  //ע�ⲻ��������д��  ���鿪�ٿռ�ʱ�����ó���
	char *number = new char[n + 1];
	memset(number, '0', n);//��ǰn��Ԫ������Ϊ�ַ�0
	number[n] = '\0';
	while (!CreateNumber(number))
	{
		//cout << number << " ";
		Print(number);
	}
}


//�ַ���ģ�������ӷ�
//ģ��ÿ���ۼ�1
bool CreateNumber(char *number)
{
	bool IsOverFlow = false;
	int NTakeOver = 0;  //��λλ
	int len = strlen(number);
	for (int i = len - 1; i >= 0; i--)
	{
		int sum = number[i] - '0' + NTakeOver;  //�н�λ��ʱ��ѭ����������ǰλ���Ͻ�λ
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
				NTakeOver = 1;  //��λ
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


//��ӡ
void Print(char *a)
{
	char *tmp = a;
	while (*tmp == 0)  //������һ��������ַ���ʱ���ڽ������
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