#include<iostream>
using namespace std;

//��һ�����������η�
double	PowerByPositive(double base, size_t exponent);//��������
double Power(double base, int exponent)
{
	//��������0��ʱ�򷵻�ֵӦ����0
	if (base - 0.000001 < 0)
		//double���͵�������ֱ�Ӻ�0���Ƚ�
	{
		return 1.0;
	}
	//��ָ���Ǹ�����ʱ����Ҫ�����������
	if (exponent < 0)
	{
		return 1.0 / PowerByPositive(base, -exponent);
	}
	//ָ��������
	else
		return PowerByPositive(base, exponent);
}

//����ָ��������
//double PowerByPositive(double base, size_t exponent)
//{
//	double result = 1.0;
//	while (exponent>1)
//	{
//		result *= base;
//		exponent--;
//	}
//	return result;
//}

//����Ч���㷨��һ���������������η�
//ż���η�����ָ��һ���ƽ��a^n=a^(n/2)*a^(n/2);
//�����η�                  a^n=a^((n-1)/2)*a^((n-1)/2);
//���Կ����õݹ������
double PowerByPositive(double base, size_t exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;
	double result = PowerByPositive(base, exponent >> 1);
	result *= result;
	if (exponent & 1 == 1)
		result *= base;
	return result;
}
int main()
{
	double ret = Power(0.00000000002, 5);
	double ret2 = Power(2.0, 3);
	cout << ret2 << endl;
	getchar();
	return 0;
}