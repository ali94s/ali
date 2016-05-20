#include<iostream>
using namespace std;
//给定一个数组  判断这个数组是不是某个二叉搜索树的后序遍历结果(任意两个数字不相同)

//二叉搜索树的左子树小于根节点  右子树大于根节点
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
	//后序遍历的最后一个节点是根节点
	int root = a[len - 1];
	//找到左子树的节点
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
	//判断左子树是不是满足
	if (i>0)
		left = IsPostOrder(a, i);
	//右子树的判断
	bool right = true;
	if (i < len - 1)
		right = IsPostOrder(a + i, len - i - 1);
	return left&&right;
}
int main()
{


	return 0;
}