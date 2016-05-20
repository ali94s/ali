#include<iostream>
#include<stack>
using namespace std;
//输入一个人栈的进栈顺序和出栈顺序 判断这个出栈顺序是不是这个栈的出栈顺序
bool IsSame(int *push,int *pop,int len)
{
	bool ret = false;
	if (push != NULL && pop != NULL && len > 0)
	{
		//借助一个辅助栈来入给定的进栈顺序的元素
		stack<int> Stmp;
		int *ppush = push;
		int *ppop = pop;
		while (ppop - pop < len)
		{
			//当栈为空或者栈顶元素不等于此时出栈顺序的元素
			while (Stmp.empty() || Stmp.top()!=*ppop)
			{
				if (ppush - push == len)
					break;
				//进行压栈  在进栈顺序中寻找
				Stmp.push(*ppush);
				ppush++;
			}
			if (Stmp.top() != *ppop)
				break;
			if (Stmp.top() == *ppop)
			{
				//此时的栈顶元素与出栈顺序中的元素相等
				Stmp.pop();
				*ppop++;
			}
		}
		if (ppop - pop == len&&Stmp.empty())
			ret = true;
	}
	return ret;
}


int main()
{
	int push[] = { 1, 2, 3, 4, 5 };
	int pop[] = { 5, 4, 3, 2, 1 };
	if (IsSame(push, pop, 5))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
	system("pause");
	return 0;
}