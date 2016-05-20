#include<iostream>
using namespace std;

//求一个数的整数次方
double	PowerByPositive(double base, size_t exponent);//函数声明
double Power(double base, int exponent)
{
	//当底数是0的时候返回值应该是0
	if (base - 0.000001 < 0)
		//double类型的数不能直接和0做比较
	{
		return 1.0;
	}
	//当指数是负数的时候需要将结果进行求倒
	if (exponent < 0)
	{
		return 1.0 / PowerByPositive(base, -exponent);
	}
	//指数是正数
	else
		return PowerByPositive(base, exponent);
}

//计算指数是正数
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

//更高效的算法求一个正常数的正数次方
//偶数次方等于指数一半的平方a^n=a^(n/2)*a^(n/2);
//奇数次方                  a^n=a^((n-1)/2)*a^((n-1)/2);
//所以可以用递归来解决
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