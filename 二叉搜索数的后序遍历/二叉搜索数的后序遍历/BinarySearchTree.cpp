#include<iostream>
using namespace std;
//����һ������  �ж���������ǲ���ĳ�������������ĺ���������(�����������ֲ���ͬ)

//������������������С�ڸ��ڵ�  ���������ڸ��ڵ�
struct BinaryTreeNode
{
	int _value;
	BinaryTreeNode *_left;
	BinaryTreeNode *_right;
};
bool  IsPostOrder(int a[],int len)
{
	if (a == NULL || len <= 0)
		return false;
	//������������һ���ڵ��Ǹ��ڵ�
	int root = a[len - 1];
	//�ҵ��������Ľڵ�
	int i = 0;
	for (i; i < len - 1; ++i)
	{
		if (a[i]>root)
			break;
	}
	int j = i;
	for (j; j < len - 1; j++)
	{
		if (a[j] < root)
			return false;
	}
	bool left = true;
	//�ж��������ǲ�������
	if (i>0)
		left = IsPostOrder(a, i);
	//���������ж�
	bool right = true;
	if (i < len - 1)
		right = IsPostOrder(a + i, len - i - 1);
	return left&&right;
}
int main()
{


	return 0;
}