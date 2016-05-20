#include<iostream>
using namespace std;


//统计从1到n的整数中所有1出现的次数
//传统算法    拿到一个数就进行对10取余数  在进行除10
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