#include<iostream>
#include<stack>
using namespace std;
//����һ����ջ�Ľ�ջ˳��ͳ�ջ˳�� �ж������ջ˳���ǲ������ջ�ĳ�ջ˳��
bool IsSame(int *push,int *pop,int len)
{
	bool ret = false;
	if (push != NULL && pop != NULL && len > 0)
	{
		//����һ������ջ��������Ľ�ջ˳���Ԫ��
		stack<int> Stmp;
		int *ppush = push;
		int *ppop = pop;
		while (ppop - pop < len)
		{
			//��ջΪ�ջ���ջ��Ԫ�ز����ڴ�ʱ��ջ˳���Ԫ��
			while (Stmp.empty() || Stmp.top()!=*ppop)
			{
				if (ppush - push == len)
					break;
				//����ѹջ  �ڽ�ջ˳����Ѱ��
				Stmp.push(*ppush);
				ppush++;
			}
			if (Stmp.top() != *ppop)
				break;
			if (Stmp.top() == *ppop)
			{
				//��ʱ��ջ��Ԫ�����ջ˳���е�Ԫ�����
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